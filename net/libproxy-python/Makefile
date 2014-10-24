# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-python/Makefile,v 1.1 2011/01/12 13:10:54 kwm Exp $

PORTREVISION=	0
CATEGORIES=	net lang
PKGNAMESUFFIX=	-python

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	python binding for libproxy

LIB_DEPENDS=	libproxy.so:${PORTSDIR}/net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USES+=		python

LIBPROXY_SLAVE=	python

do-build:
# empty	

post-build:
	${PYTHON_CMD} -Qold ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/bindings/python
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/bindings/python

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
.for file in libproxy.py libproxy.pyc libproxy.pyo
	${INSTALL_DATA} ${WRKSRC}/bindings/python/${file} \
		${STAGEDIR}${PYTHON_SITELIBDIR}
.endfor

.include "${MASTERDIR}/Makefile"
