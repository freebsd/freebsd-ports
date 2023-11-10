PORTNAME=	hunspell
DISTVERSION=	23.10
CATEGORIES=	textproc
PKGNAMEPREFIX=	cy-

MAINTAINER=	ceri@FreeBSD.org
COMMENT=	Welsh Hunspell dictionaries
WWW=		https://github.com/techiaith/hunspell-cy

LICENSE=	LGPL3+

USE_GITHUB=	yes
GH_ACCOUNT=	techiaith
GH_PROJECT=	hunspell-cy

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/cy_GB.aff \
		${DATADIR}/cy_GB.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cy_GB.aff ${WRKSRC}/cy_GB.dic ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
