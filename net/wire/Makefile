# New ports collection makefile for:	wire
# Date created:		2006-11-23
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	wire
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.zankasoftware.com/dist/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Wire is a screen-oriented command line Wired client

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir="${LOCALBASE}/lib" --includedir="${LOCALBASE}/include"
USE_GMAKE=	yes
USE_ICONV=	yes

PLIST_FILES=	bin/wire

MAN1=		wire.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

.include <bsd.port.post.mk>
