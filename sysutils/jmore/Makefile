PORTNAME=	jmore
DISTVERSION=	0.5.20251030
DISTVERSIONSUFFIX= -g${GH_TAGNAME}
CATEGORIES=	sysutils

MAINTAINER=	vermaden@interia.pl
COMMENT=	FreeBSD Jail listing and managing utility
WWW=		https://github.com/vermaden/jmore

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	vermaden
GH_PROJECT=	jmore
GH_TAGNAME=	9b72e97

NO_ARCH=	YES
NO_BUILD=	YES

PLIST_FILES=	sbin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jmore \
	${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>
