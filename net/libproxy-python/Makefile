# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-python/Makefile,v 1.1 2011/01/12 13:10:54 kwm Exp $

PORTREVISION=	0
CATEGORIES=	net lang
PKGNAMESUFFIX=	-python

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	python binding for libproxy

RUN_DEPENDS=	libproxy>=${PORTVERSION}:net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}/bindings/python
NO_ARCH=	yes
NO_BUILD=	yes
USES=		python

LIBPROXY_SLAVE=	python

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
