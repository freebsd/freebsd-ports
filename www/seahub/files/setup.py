#!/usr/bin/env python
#-*- coding:utf-8 -*-

from setuptools import setup, find_packages

setup(
	name = 'seahub',
	version = '3.1.3',
	packages = find_packages(),
	zip_safe = False,

	description = 'Web frontend for Seafile',
	long_description = """Seahub is the web frontend for seafile-server.""",
	maintainer = 'Yan, Jingfeng',
	maintainer_email = 'yan_jingfeng@yahoo.com',

	license = 'http://www.apache.org/licenses/LICENSE-2.0.html',
	keywords = ('seafile', 'seahub'),
	platforms = 'Independant',

	include_package_data = True,
	
	#
	# The requirements.txt listed the packages and version requirements.
	# We picked a specific version for each packages only for FreeBSD port
	# pkg-plist.
	#
	install_requires = [
		'lockfile==0.10.2',
		'Django==1.5.9',
		'Djblets==0.6.14',
		'pillow==2.6.1',
		'python-dateutil==2.2',
		'chardet==2.3.0',
		'daemon==1.1',
		'flup==1.0.2',
		'gunicorn==18.0',
		'six==1.8.0',
		],
	dependency_links = [
		'http://downloads.reviewboard.org/releases/Djblets/0.6/'
		],
	)
