# New ports collection makefile for:	wire
# Date created:		2006-11-23
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	wire
PORTVERSION=	1.1.3
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://mirror.mcx2.org/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Wire is a screen-oriented command line Wired client

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS=${CPPFLAGS} LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--libdir="${LOCALBASE}/lib" --includedir="${LOCALBASE}/include"
MAKE_ENV=	CPPFLAGS=${CPPFLAGS}

USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_ICONV=	yes

PLIST_FILES=	bin/wire

MAN1=		wire.1

#.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

#.include <bsd.port.post.mk>

#TODO this is fucking dirty :(
do-build:
	cd ${WRKSRC} ;${GMAKE}

.include <bsd.port.mk>
