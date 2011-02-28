# New ports collection makefile for:	libproxy
# Date created:		26 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libproxy
PORTVERSION=	0.2.3
PORTREVISION?=	1
CATEGORIES?=	net devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Library that provides automatic proxy configuration management

USE_GMAKE=	yes
USE_GNOME+=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		ac_cv_func_malloc_0_nonnull=yes
CONFIGURE_ARGS?=--without-gnome --without-kde --without-webkit \
		--without-mozjs --without-networkmanager --with-python \
		--with-envvar --with-file

PLIST_SUB+=	VERSION=${PORTVERSION}

.if !defined(LIBPROXY_SLAVE)
USE_LDCONFIG=	yes
USE_PYTHON=	2.5+

post-build:
	${PYTHON_CMD} -Qold ${PYTHON_LIBDIR}/compileall.py \
	    	${WRKSRC}/src/bindings/python
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
	    	${WRKSRC}/src/bindings/python

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/bindings/python/libproxy.pyc \
		${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/src/bindings/python/libproxy.pyo \
		${PYTHON_SITELIBDIR}
.endif

.include <bsd.port.mk>
