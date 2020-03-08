# $FreeBSD$

PORTNAME=	scancode-toolkit
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.2
PORTREVISION=	2
CATEGORIES=	textproc python

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Scans code for license, copyright, package and documented dependencies

LICENSE=	APACHE20 CC0-1.0
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/apache-2.0.LICENSE
LICENSE_FILE_CC0-1.0=	${WRKSRC}/cc0-1.0.LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nltk>=3.2:textproc/py-nltk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}url>=0.1.4:www/py-url@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fingerprints>=0.5.4:textproc/py-fingerprints@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}patch>=1.15:devel/py-patch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bz2file>=0.98:archivers/py-bz2file@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}backports.os=0.1.1:devel/py-backports.os@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.16.0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}text-unidecode>=1.0:converters/py-text-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bitarray>=0.8.1:devel/py-bitarray@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intbitset>=2.3.0:devel/py-intbitset@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boolean.py>=3.5:devel/py-boolean.py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}license-expression>=0.99:textproc/py-license-expression@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyahocorasick>=1.1:textproc/py-pyahocorasick@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}saneyaml>=0:devel/py-saneyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.0.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.0.0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer.six>=20170720:textproc/py-pdfminer.six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.4:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}binaryornot>=0.4.0:devel/py-binaryornot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=3.0.0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.2.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pefile>=2018.8.8:devel/py-pefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymaven-patch>=0.2.4:devel/py-pymaven-patch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packageurl-python>=0.7.0:textproc/py-packageurl-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.11.0:devel/py-xmltodict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}javaproperties>=0.5:devel/py-javaproperties@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click6>=6.0.0:devel/py-click6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=0.4.0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=17.4:devel/py-attrs@${PY_FLAVOR} \
		${PY_TYPING} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.23:textproc/py-MarkupSafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-tools>=0.5.4:misc/py-spdx-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicodecsv>=0:devel/py-unicodecsv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yg.lockfile>=2.0.1:devel/py-yg.lockfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zclockfile>=1.0.0:devel/py-zclockfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}contextlib2>=0:devel/py-contextlib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tempora>=0:devel/py-tempora@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.timing>=0:devel/py-jaraco.timing@${PY_FLAVOR} \
		${PY_IPADDRESS} \
		${LOCALBASE}/bin/7z:archivers/p7zip \
		${LOCALBASE}/bin/file:sysutils/file \
		${LOCALBASE}/lib/libarchive.so:archivers/libarchive

USES=		python:2.7
USE_PYTHON=	distutils autoplist noflavors
USE_GITHUB=	yes
GH_ACCOUNT=	nexB

NO_ARCH=	yes

# The upstream package comes with several Python packages of libmagic, p7zip
# and zlib that include precompiled binaries for different architectures:
#
# - plugins/extractcode-7z-ARCH
#   	bin/
# - plugins/extractcode-libarchive-ARCH
#   	lib/
# - plugins/typecode-libmagic-ARCH
#   	/data
#   	/lib
#
# We use as ARCH the "manylinux_1_x86_64" architecture to get the directory
# structure. The binary files will be overwritten in the post-install target
# when the relative symlinks are created.
BOGUSLNKS=	${LOCALBASE}/bin/7z \
		${LOCALBASE}/libexec/p7zip/7z.so \
		${LOCALBASE}/lib/libarchive.so \
		${LOCALBASE}/lib/libmagic.so \
	       	${LOCALBASE}/share/file/magic.mgc

.for _b in ${BOGUSLNKS}
BOGUSDIR_${_b}=	`${DIRNAME} ${_b}`
.endfor

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -or -name "*.bak" -delete

do-build:
	# Build the port and the plugin packages
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_BUILD_TARGET} ${PYDISTUTILS_BUILDARGS})
	@(cd ${BUILD_WRKSRC}/plugins/extractcode-7z-manylinux1_x86_64; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_BUILD_TARGET} ${PYDISTUTILS_BUILDARGS})
	@(cd ${BUILD_WRKSRC}/plugins/extractcode-libarchive-manylinux1_x86_64; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_BUILD_TARGET} ${PYDISTUTILS_BUILDARGS})
	@(cd ${BUILD_WRKSRC}/plugins/typecode-libmagic-manylinux1_x86_64; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_BUILD_TARGET} ${PYDISTUTILS_BUILDARGS})

do-install:
	# Install scancode and the plugin packages. After each installation run
	# the newly created ${_PYTHONPKGLIST} is renamed for later processing.
	(cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_INSTALL_TARGET} ${PYDISTUTILS_INSTALLARGS})
	@${MV} ${_PYTHONPKGLIST} ${_PYTHONPKGLIST}.scancode
	(cd ${INSTALL_WRKSRC}/plugins/extractcode-7z-manylinux1_x86_64; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_INSTALL_TARGET} ${PYDISTUTILS_INSTALLARGS})
	@${MV} ${_PYTHONPKGLIST} ${_PYTHONPKGLIST}.extractcode-7z
	(cd ${INSTALL_WRKSRC}/plugins/extractcode-libarchive-manylinux1_x86_64; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_INSTALL_TARGET} ${PYDISTUTILS_INSTALLARGS})
	@${MV} ${_PYTHONPKGLIST} ${_PYTHONPKGLIST}.extractcode-libarchive
	(cd ${INSTALL_WRKSRC}/plugins/typecode-libmagic-manylinux1_x86_64; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_INSTALL_TARGET} ${PYDISTUTILS_INSTALLARGS})
	@${MV} ${_PYTHONPKGLIST} ${_PYTHONPKGLIST}.typecode-libmagic
	# Merge the package lists from the previous install steps into one
	# ${_PYTHONPKGLIST}
	@${CAT} ${_PYTHONPKGLIST}.scancode ${_PYTHONPKGLIST}.extractcode-7z ${_PYTHONPKGLIST}.extractcode-libarchive ${_PYTHONPKGLIST}.typecode-libmagic > ${_PYTHONPKGLIST}

post-install:
	# Create bogus directories and files that will be used as sources for
	# the relative symlinks in the stagedir. Also keep track of the
	# files/directory that need to be created for later removal.
.for _f in ${BOGUSLNKS}
	@if ! ${TEST} -d ${STAGEDIR}${BOGUSDIR_${_f}}; then \
		${MKDIR} ${STAGEDIR}${BOGUSDIR_${_f}} && \
	       	${ECHO} ${STAGEDIR}${BOGUSDIR_${_f}} >> ${WRKDIR}/.bogusdirs ; \
	fi

	@${ECHO} DUMMY > ${STAGEDIR}${_f}
	@${ECHO} ${STAGEDIR}${_f} >> ${WRKDIR}/.bogusdirs
.endfor

	# Create the relative symlinks using the bogus libmagic, p7zip and zlib
	# as sources to overwrite the placeholder that were created with the
	# post-extract target.
	@${RLN} ${STAGEDIR}${LOCALBASE}/bin/7z ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/extractcode_7z/bin/
	@${RLN} ${STAGEDIR}${LOCALBASE}/libexec/p7zip/7z.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/extractcode_7z/bin/
	@${RLN} ${STAGEDIR}${LOCALBASE}/lib/libarchive.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/extractcode_libarchive/lib/
	@${RLN} ${STAGEDIR}${LOCALBASE}/share/file/magic.mgc ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/typecode_libmagic/data/
	@${RLN} ${STAGEDIR}${LOCALBASE}/lib/libmagic.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/typecode_libmagic/lib/

	# Remove all bogus source files/directories to pass stage qa
	@${RM} -r `${CAT} ${WRKDIR}/.bogusdirs`

.include <bsd.port.mk>
