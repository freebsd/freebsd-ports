# ex:ts=8
# New ports collection makefile for:	librsync
# Date created:			Mar 13, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librsync
PORTVERSION=	0.9.7
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for delta compression of streams

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-shared --disable-trace
USE_LDCONFIG=	yes

MAN3=	librsync.3

post-patch:
	@${REINPLACE_CMD} -e 's|= rdiff.1|=|g' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
