PORTNAME=	pantomime
DISTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	mail gnustep
MASTER_SITES=	SAVANNAH/gnustep-nonfsf/
DISTNAME=	Pantomime-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail/MIME handling library for GNUstep
WWW=		http://www.collaboration-world.com/cgi-bin/project/index.cgi?pid=3

LICENSE=	LGPL21

USES=		gnustep iconv ssl

# The use of libiconv shouldn't be necessary, but a build dependency installs
# it and we end up picking up the header.
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

MAKE_ARGS+=	LIBRARIES_DEPEND_UPON='${ICONV_LIB} -lssl'

DEFAULT_LIBVERSION=	${DISTVERSION:R}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=       -Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
