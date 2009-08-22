# Ports collection makefile for:	ccxstream
# Date created:				2004-08-14
# Whom:					Michael Handler <handler@grendel.net>
#
# $FreeBSD$
#

PORTNAME=		ccxstream
PORTVERSION=		1.0.15
PORTREVISION=		1
CATEGORIES=		net
MASTER_SITES=		SF/xbplayer/XStream%20Servers/ccXStream%20${PORTVERSION}%20for%20Linux

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Stream media files to XBox Media Center via XBMSP

OPTIONS=		SO_KEEPALIVE "Build with SO_KEEPALIVE" ON \
			TCP_NODELAY "Build with TCP_NODELAY" OFF

USE_GMAKE=		yes
USE_RC_SUBR=		ccxstream

PLIST_FILES=		\
			bin/ccxtest \
			sbin/ccxstream

.if !defined(NOPORTDOCS)
PORTDOCS=		README ChangeLog TODO xbmsp-xml.txt xbmsp.txt
.endif

do-install:
	@${MKDIR} ${PREFIX}/sbin
	@${INSTALL_PROGRAM} ${WRKSRC}/ccxstream ${PREFIX}/sbin
	@${INSTALL_PROGRAM} ${WRKSRC}/ccxtest ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

# enable SO_KEEPALIVE
.if defined(WITH_SO_KEEPALIVE)
CFLAGS+=	-DSO_KEEPALIVE
.endif

# enable TCP_NODELAY
.if defined(WITH_TCP_NODELAY)
CFLAGS+=	-DTCP_NODELAY
.endif

.include <bsd.port.post.mk>
