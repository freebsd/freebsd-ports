#!/usr/bin/env ruby
=begin -*-mode: ruby-*-

  MoZiLLa.in

  Copyright (c) 2002, Alan Eldridge
  All rights reserved.
  
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions 
  are met:
  
  * Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
  
  * Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
  
  * Neither the name of the copyright owner nor the names of its
  contributors may be used to endorse or promote products derived
  from this software without specific prior written permission.
  
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

  $Id: firefox.rb,v 1.1 2005/03/05 01:49:02 marcus Exp $

  2002-12-16 Alan Eldridge <alane@geeksrus.net>

=end

X11BIN = "/usr/X11R6/bin"
NAME = File::basename($0, ".rb")
APP_PATH = File::join(X11BIN, NAME)

if !File::executable?(APP_PATH)
  raise "File '#{APP_PATH}' not found. Giving up." 
elsif ($display = ENV["DISPLAY"]) == nil
  raise "Environment variable DISPLAY not found. Giving up."
end 

if ARGV.size > 0
  if ARGV[0] == "--debug"
    ARGV.shift
  else
    $stdin.reopen(File::open("/dev/null", "r"))
    $stdout.reopen(File::open("/dev/null", "w"))
    $stderr.reopen(File::open("/dev/null", "w"))
  end
end

if ARGV.size < 1
  $url = nil
else
  $url = ARGV.pop
  $url.sub!(/^ghelp:/, "file:") 
end

IO::popen("xwininfo -display #{$display} -root -tree") {
  |io|
  if NAME != "firefox"
    $windows = io.grep(%r<"Mozilla"\s+"navigator:\s*browser">)
  else
    $windows = io.grep(%r<Firefox-bin.*>)
  end
}

if $windows.size > 0
  $id = $windows.map { 
    |s| s.strip.split.first 
  }.sort.first
  $args = [ "-id", $id, "-raise", "-remote" ]
  $args.push($url ? "\"openURL(#{$url},new-window)\"" : 
	    "\"xfeDoCommand(openBrowser)\"")
else
  $args = ARGV
  $args.push("\"#{$url}\"") if $url
end

fork {
  exec(([APP_PATH] + $args).join(" "))
}
exit!

#EOF
