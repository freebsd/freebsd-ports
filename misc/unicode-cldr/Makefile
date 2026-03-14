PORTNAME=	unicode-cldr
DISTVERSION=	48.1
CATEGORIES=	misc
MASTER_SITES=	https://unicode.org/Public/cldr/${DISTVERSION}/
DISTFILES=	cldr-common-${DISTVERSION}.zip

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Unicode Common Locale Data Repository
WWW=		https://cldr.unicode.org/

LICENSE=	Unicode-3.0
LICENSE_NAME=	Unicode License v3
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		zip

NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/unicode/cldr

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DATADIR}/ "! -name *\.md ! -name LICENSE"

.include <bsd.port.mk>
