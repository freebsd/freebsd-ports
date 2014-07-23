# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

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
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--libdir="${PREFIX}/lib" --includedir="${PREFIX}/include"

USE_OPENSSL=	yes
USES=		iconv gmake

PLIST_FILES=	bin/wire

MAN1=		wire.1

#.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	libreadline.so.6:${PORTSDIR}/devel/readline
.endif

#.include <bsd.port.post.mk>

#TODO this is fucking dirty :(
NO_STAGE=	yes
do-build:
	cd ${WRKSRC} ;${MAKE_CMD}

.include <bsd.port.mk>
