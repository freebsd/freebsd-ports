# New ports collection makefile for:	mhash
# Date created:		Mon Jun 28 17:59:13 PDT 1999
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	mhash
PORTVERSION=	0.8.13
CATEGORIES=	security
MASTER_SITES=	http://mhash.sourceforge.net/dl/

MAINTAINER=	roam@FreeBSD.org

INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--with-LDFLAGS="${PTHREAD_LIBS}"

MAN3=		mhash.3

post-extract:
	${CP} ${LOCALBASE}/bin/libtool ${WRKSRC}

.include <bsd.port.mk>
