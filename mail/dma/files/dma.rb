#!/usr/bin/env ruby
# Copyright (c) 2009 Daniel Roethlisberger <daniel@roe.ch>
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice unmodified, this list of conditions, and the following
#    disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
# 
# $FreeBSD$

# Wrapper around dma(8) which implements the missing -t sendmail option.
# WARNING: The address parsing is very incomplete and might break.

require 'open3'

dma = $0.gsub(/.rb$/, '')

if ARGV.delete "-t"
	msg = STDIN.read
	head, cr, body = msg.split(/\n(\r?)\n/, 2)
	head = head + "\n"
	tmphead = head.gsub(/\n\s+/m, ' ')
	rcpts = []
	tmphead.gsub(/^(?:to|cc|bcc):\s.*$/i) do |match|
		match.sub(/^[^:]+:\s*/, '').split(/\s*[,;]\s*/).each do |addr|
			rcpts << addr.sub(/.*<([^<>]+)>.*/, '\\1')
		end
	end
	head.gsub!(/^bcc:.*\n/i, '')
	Open3.popen3(dma, *ARGV.concat(rcpts)) do |i,o,e|
		i.write head
		i.write "#{cr}\n"
		i.write body
		i.close_write
		print o.read
		print e.read
	end
else
	exec(dma, *ARGV)
end

