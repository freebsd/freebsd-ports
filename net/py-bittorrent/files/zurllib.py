# Written by John Hoffman
# see LICENSE.txt for license information

from httplib import HTTPConnection
from urlparse import urlparse
import socket
from gzip import GzipFile
from StringIO import StringIO
from urllib import quote, unquote
from __init__ import version

MAX_REDIRECTS = 10

class urlopen:
    def __init__(self, url):
	self.tries = 0
	self._open(url)

    def _open(self, url):
	self.tries += 1
	if self.tries > MAX_REDIRECTS:
	    raise IOError, ('http error', 500,
			    "Internal Server Error: Redirect Recursion")
	(scheme, netloc, path, pars, query, fragment) = urlparse(url)
	if scheme != 'http':
	    raise IOError, ('url error', 'unknown url type', scheme, url)
	url = path
	if pars:
	    url += ';'+pars
	if query:
	    url += '?'+query
#	if fragment:
	self.connection = HTTPConnection(netloc)
	self.connection.request('GET', url, None,
				{ 'User-Agent': 'BitTorrent/' + version,
				  'Accept-Encoding': 'gzip' } )
	self.response = self.connection.getresponse()
	status = self.response.status
	if status in (301,302):
	    try:
		self.connection.close()
	    except:
		pass
	    self._open(self.response.getheader('Location'))
	    return
	if status != 200:
	    raise IOError, ('http error', status, self.response.reason)

    def read(self):
	data = self.response.read()
	if self.response.getheader('Content-Encoding','').find('gzip') >= 0:
	    try:
		compressed = StringIO(data)
		f = GzipFile(fileobj = compressed)
		data = f.read()
	    except:
		raise IOError, ('http error', 'got corrupt response')
	return data

    def close(self):
	self.connection.close()
