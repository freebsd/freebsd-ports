#!/usr/bin/env ruby

require 'json'

data = JSON.parse(STDIN.read)

in_r, in_w = IO.pipe
in_w.sync = true

pid = Process.spawn({}, data['executable'], *data['arguments'], { in: in_r, out: data['stdout'], err: data['stderr'] })
in_w.write(data['input'])
in_w.close

Process.wait(pid)
exit_code = $?.exitstatus

File.write(data['exitcode'], exit_code)
exit(exit_code)
