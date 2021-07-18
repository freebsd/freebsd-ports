PORTNAME=	ammonite
DISTVERSION=	2.4.0
CATEGORIES=	shells java
MASTER_SITES=	https://github.com/lihaoyi/Ammonite/releases/download/${PORTVERSION}/
DISTNAME=	2.13-${PORTVERSION}
EXTRACT_SUFX=
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	Provides a system shell in the high-level Scala language

LICENSE=	MIT

USE_JAVA=	yes
JAVA_VERSION=	1.8+

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/ammonite

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
