# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	jmref
PORTVERSION=	18.4
CATEGORIES=	multimedia
MASTER_SITES=	http://iphome.hhi.de/suehring/tml/download/
DISTNAME=	jm${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	JM Reference Software

USES=		dos2unix gmake zip
WRKSRC=		${WRKDIR}/JM

PLIST_FILES=	bin/ldecod bin/lencod \
		bin/rtp_loss bin/rtpdump

DOS2UNIX_FILES=	Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ldecod.exe \
		${STAGEDIR}${PREFIX}/bin/ldecod
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lencod.exe \
		${STAGEDIR}${PREFIX}/bin/lencod
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rtp_loss.exe \
		${STAGEDIR}${PREFIX}/bin/rtp_loss
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rtpdump.exe \
		${STAGEDIR}${PREFIX}/bin/rtpdump

.include <bsd.port.mk>
