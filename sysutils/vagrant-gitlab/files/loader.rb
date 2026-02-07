# RubyEncoder v1.0 loader
_v = RUBY_VERSION.scan(/^\d+\.\d+\.\d+/)[0].delete('.')
_v = '' if _v.to_i < 190
_p = RUBY_PLATFORM.scan(/^([A-Za-z0-9_]+\.)?([A-Za-z0-9_]+)-([A-Za-z_]+)/)[0]
_p.shift
#_p = RUBY_PLATFORM.scan(/^([A-Za-z0-9_]+)-([A-Za-z_]+)/)[0]
_d = File.expand_path(File.dirname(__FILE__))
_f = [_d + '/rgloader' + _v + '.' + _p[1] + '.' + _p[0],
      _d + '/rgloader' + _v + '.' + _p[1],
      _d + '/rgloader' + _v.chop + '.' + _p[1] + '.' + _p[0],
      _d + '/rgloader' + _v.chop + '.' + _p[1]]

_fl = false
for x in _f do
  begin
    require x
    _fl = true
    break
  rescue LoadError
  end
end

if not _fl then
  raise LoadError, "The RubyEncoder loader is not installed. Please visit the http://www.rubyencoder.com/loaders/ RubyEncoder site to download the required loader for '"+_p[1]+"' and unpack it into '"+_d+"' directory to run this protected script."
end
