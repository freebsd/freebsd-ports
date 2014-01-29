# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-python/Makefile,v 1.1 2011/01/12 13:10:54 kwm Exp $

PORTREVISION=	0
CATEGORIES=	net lang
PKGNAMESUFFIX=	-python

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	python binding for libproxy

LIB_DEPENDS=	proxy.1:${PORTSDIR}/net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USE_PYTHON=	yes

LIBPROXY_SLAVE=	python

NO_STAGE=	yes
do-build:
# empty	

post-build:
	${PYTHON_CMD} -Qold ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/bindings/python
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/bindings/python

do-install:
.for file in libproxy.py libproxy.pyc libproxy.pyo
	${INSTALL_DATA} ${WRKSRC}/bindings/python/${file} \
		${PYTHON_SITELIBDIR}
.endfor

.include "${MASTERDIR}/Makefile"
