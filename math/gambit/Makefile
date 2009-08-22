# ex:ts=8
# Ports collection makefile for:	gambit
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gambit
PORTVERSION=	0.2007.12.04
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A library of tools for doing computation in game theory

USE_GNOME=	gnometarget gtk20
USE_WX=		2.6+
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

CPPFLAGS=	${PTHREAD_CFLAGS}
LDFLAGS=	${PTHREAD_LIBS}
.if !defined(CFLAGS) || ${CFLAGS:M-fno-strict-aliasing*} == ""
CFLAGS+=	-O2 -fno-strict-aliasing
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
