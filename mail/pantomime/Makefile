# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pantomime
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	mail gnustep
MASTER_SITES=	SAVANNAH/gnustep-nonfsf/
DISTNAME=	Pantomime-${PORTVERSION}

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Mail/MIME handling library for GNUstep

LICENSE=	LGPL21

# The use of libiconv shouldn't be necessary, but a build dependency installs
# it and we end up picking up the header.
MAKE_ARGS+=	LIBRARIES_DEPEND_UPON='${ICONV_LIB} -lssl'
USES=		gnustep iconv ssl
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

DEFAULT_LIBVERSION=	1.2

.include <bsd.port.mk>
