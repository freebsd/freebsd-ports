PORTNAME=	gnumail
DISTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	mail gnustep
MASTER_SITES=	SAVANNAH/gnustep-nonfsf/
DISTNAME=	GNUMail-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep mail client
WWW=		https://www.nongnu.org/gnustep-nonfsf/gnumail/

LICENSE=	GPLv2+

LIB_DEPENDS=	libPantomime.so:mail/pantomime \
		libAddresses.so:mail/addresses

USES=		cpe gnustep
CPE_VENDOR=	gnu
USE_GNUSTEP=	back build gui base
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Frameworks/GNUMail.framework/Versions/1/libGNUMail.so.1.4.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/Colors.prefs/Colors
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/Import.bundle/Import
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/PGP.bundle/PGP
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/Fonts.prefs/Fonts
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/Compose.prefs/Compose
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/Filtering.prefs/Filtering
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/Viewing.prefs/Viewing
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/Sending.prefs/Sending
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/Receiving.prefs/Receiving
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/Emoticon.bundle/Emoticon
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/Advanced.prefs/Advanced
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/MIME.prefs/MIME
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/ApplicationSupport/GNUMail/Account.prefs/Account
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GNUMail.app/GNUMail

.include <bsd.port.post.mk>
