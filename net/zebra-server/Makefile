# New ports collection makefile for:	zebra-server
# Date created:				14 Nov 2000
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zebra-server
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/zebra/
DISTNAME=	zebra-${PORTVERSION:S/0./0pl/}

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	yaz.1:${PORTSDIR}/net/yaz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-yazconfig=${LOCALBASE}/bin
CONFIGURE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS}

post-install:
.if !defined(NOPORTDOCS)
		@(cd ${WRKSRC}/doc; ${MAKE} install)
.endif

.include <bsd.port.mk>
