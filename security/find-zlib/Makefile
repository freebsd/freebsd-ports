# Created by: trevor

PORTNAME=	find_zlib
PORTVERSION=	1.9
CATEGORIES=	security
MASTER_SITES=	http://zlib.net/
DISTNAME=	find-zlib
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scans files for statically linked zlib (libz) code

DEPRECATED=	Deprecated, no longer relevant
EXPIRATION_DATE=2022-03-31

LICENSE=	GPLv2

NO_BUILD=	none

USES=		perl5 shebangfix
USE_PERL5=	run

PLIST_FILES=	bin/find-zlib
SHEBANG_FILES=	find-zlib

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
