# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	jmref
PORTVERSION=	19.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://iphome.hhi.de/suehring/tml/download/
DISTNAME=	jm${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	JM Reference Software

LICENSE=	ISO_IEC ITU
LICENSE_COMB=	multi
LICENSE_NAME_ISO_IEC=	ISO/IEC Source Code License
LICENSE_NAME_ITU=	ISO/IEC Source Code License
LICENSE_FILE_ISO_IEC=	${WRKSRC}/COPYRIGHT_ISO_IEC.txt
LICENSE_FILE_ITU=	${WRKSRC}/COPYRIGHT_ISO_IEC.txt
LICENSE_PERMS_ISO_IEC=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_ITU=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		dos2unix gmake zip

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/JM

PLIST_FILES=	bin/ldecod bin/lencod \
		bin/rtp_loss bin/rtpdump

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
