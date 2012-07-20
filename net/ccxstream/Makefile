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

OPTIONS_DEFINE=	SO_KEEPALIVE TCP_NODELAY DOCS
OPTIONS_DEFAULT=	SO_KEEPALIVE
SO_KEEPALIVE_DESC=	Build with SO_KEEPALIVE
TCP_NODELAY_DESC=	Build with TCP_NODELAY

USE_GMAKE=		yes
USE_RC_SUBR=		ccxstream

PLIST_FILES=		bin/ccxtest \
			sbin/ccxstream

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
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

# enable SO_KEEPALIVE
.if ${PORT_OPTIONS:MSO_KEEPALIVE}
CFLAGS+=	-DSO_KEEPALIVE
.endif

# enable TCP_NODELAY
.if ${PORT_OPTIONS:MTCP_NODELAY}
CFLAGS+=	-DTCP_NODELAY
.endif

.include <bsd.port.mk>
