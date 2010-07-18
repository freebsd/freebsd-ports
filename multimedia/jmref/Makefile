# New ports collection makefile for:	jmref
# Date created:		2009-08-06
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	jmref
PORTVERSION=	17.2
CATEGORIES=	multimedia
MASTER_SITES=	http://iphome.hhi.de/suehring/tml/download/
DISTNAME=	jm${PORTVERSION}

MAINTAINER=	steve@mouf.net
COMMENT=	JM Reference Software

USE_ZIP=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/JM

PLIST_FILES=	bin/ldecod bin/lencod \
		bin/rtp_loss bin/rtpdump
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ldecod.exe ${PREFIX}/bin/ldecod
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lencod.exe ${PREFIX}/bin/lencod
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rtp_loss.exe ${PREFIX}/bin/rtp_loss
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rtpdump.exe ${PREFIX}/bin/rtpdump

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.x
.endif

.include <bsd.port.post.mk>
