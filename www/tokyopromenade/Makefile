# New ports collection makefile for:	tokyopromenade
# Date created:		2009-08-13
# Whom:			Qing Feng <qingfeng@douban.com>
#
# $FreeBSD$
#

PORTNAME=	tokyopromenade
PORTVERSION=	0.9.22
CATEGORIES=	www
MASTER_SITES=	http://fallabs.com/${PORTNAME}/

MAINTAINER=	qingfeng@douban.com
COMMENT=	A content management system

BUILD_DEPENDS=	tokyocabinet>=1.4.31:${PORTSDIR}/databases/tokyocabinet \
		fcgi-devkit>=0:${PORTSDIR}/www/fcgi
LIB_DEPENDS=	tokyocabinet:${PORTSDIR}/databases/tokyocabinet
RUN_DEPENDS=	spawn-fcgi>=0:${PORTSDIR}/www/spawn-fcgi

OPTIONS=	LUA	"Build lua extension" off

CONFIGURE_ARGS=	--enable-fcgi
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

SUB_FILES=	pkg-message

MAN1=		prommgr.1

.include <bsd.port.options.mk>

.if defined(WITH_LUA)
CONFIGURE_ARGS+=	--enable-lua
CONFIGURE_ENV+=	LDFLAGS="-L${LUA_LIBDIR}"
CFLAGS+=	-I${LUA_INCDIR}
USE_LUA=	yes
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
