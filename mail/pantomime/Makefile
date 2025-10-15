PORTNAME=	pantomime
DISTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	mail gnustep
MASTER_SITES=	SAVANNAH/gnustep-nonfsf/
DISTNAME=	Pantomime-${DISTVERSION}

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Mail/MIME handling library for GNUstep
WWW=		https://www.nongnu.org/gnustep-nonfsf/gnumail/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/Documentation/LICENSE

USES=		gnustep iconv ssl

USE_GNUSTEP=		back build
DEFAULT_LIBVERSION=	${DISTVERSION:R}

USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

MAKE_ARGS+=	LIBRARIES_DEPEND_UPON='-lssl'

post-install:
		@${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Frameworks/Pantomime.framework/Versions/${DISTVERSION:R}/libPantomime.so.${DISTVERSION}

.include <bsd.port.mk>
