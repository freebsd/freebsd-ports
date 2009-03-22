# New ports collection makefile for:	wooztalk
# Date created:		2009-03-20
# Whom:			David <tech@wooztalk.com>
#
# $FreeBSD$
#

PORTNAME=	vlconwooztalk
PORTVERSION=	0.9.9
CATEGORIES=	multimedia
MASTER_SITES=	http://www.wooztalk.com/download/
DISTNAME=	${PORTNAME}-freebsd

MAINTAINER=	tech@wooztalk.com
COMMENT=	Meet your World Wide Web neighbors with VLC

RUN_DEPENDS=	vlc:${PORTSDIR}/multimedia/vlc

USE_LDCONFIG=	yes
USE_BZIP2=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		run only on 7.x
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64
.endif

do-install:
	@${MKDIR} ${PREFIX}/share/wooztalk/plugins/vlc
	@${INSTALL_DATA} ${WRKSRC}/libvlc.so ${PREFIX}/share/wooztalk/plugins/vlc
	@${INSTALL_DATA} ${WRKSRC}/vlc.png ${PREFIX}/share/wooztalk/plugins/vlc
	@${INSTALL_DATA} ${WRKSRC}/vlc_dis.png ${PREFIX}/share/wooztalk/plugins/vlc
	@${INSTALL_DATA} ${WRKSRC}/wooztalk.html ${PREFIX}/share/vlc/http/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
