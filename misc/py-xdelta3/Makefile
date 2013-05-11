# Created by: Anonymous
# $FreeBSD$

PORTREVISION=	1
PORTEPOCH=	0
CATEGORIES?=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python module for xdelta3

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13 \
		${NONEXISTENT}:${PORTSDIR}/misc/xdelta3:build

DEPRECATED=	Abandonware
EXPIRATION_DATE=	2013-06-11

MASTERDIR=	${.CURDIR}/../../misc/xdelta3

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	xdelta3main
SLAVE_ONLY=	yes

WRKDIR=		${WRKDIRPREFIX}${MASTERDIR}/work
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}.so \
		%%PYTHON_SITELIBDIR%%/xdelta3module.so \
		%%PYTHON_SITELIBDIR%%/xdelta3.py

post-patch:	.SILENT
	${REINPLACE_CMD} -i.slave.bak -e '/^SWIG_FLAGS/s/=/& `python$$(PYVER)-config --cflags` -fpic/' \
		-e '/^xdelta3module\.so:/,/^$$/ { s/ld/$$(CC)/; \
			s/.*libpython.*\.so.*/`python$$(PYVER)-config --ldflags`/; \
			/-lc/d; }' \
		-e 's|/usr/include/python$$(PYVER)|${PYTHON_INCLUDEDIR}|' \
		-e 's|/usr/lib/python$$(PYVER)|${PYTHON_LIBDIR}|' \
		-e 's|/usr/lib/libpython|${LOCALBASE}/lib/libpython|' \
		-e '/^all:/s/:.*/: swigtgt/' \
		-e '/^PYVER/s/=.*/= ${PYTHON_VER}/' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "/^REL/s/=.*/='${PORTVERSION}'/" \
		-e "/extra_compile_args.*\[/,/]/ { s/'-O3',//; s/'-g',//; }" \
		${WRKSRC}/${PYSETUP}

post-install:
	${INSTALL_LIB} ${WRKSRC}/xdelta3module.so ${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/xdelta3.py ${PYTHONPREFIX_SITELIBDIR}

test:	build
	${PYTHON_CMD} ${WRKSRC}/xdelta3-test.py

broken-regression-test: build
	@cd ${WRKSRC} && for d in build/lib.*-${PYTHON_VER}; do \
		set -x; \
		PYTHONPATH=$${d}: ${PYTHON_CMD} testing/xdelta3-regtest.py; \
	done

.include "${MASTERDIR}/Makefile"
