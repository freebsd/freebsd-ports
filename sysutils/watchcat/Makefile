PORTNAME=	watchcat
DISTVERSION=	g20260124
CATEGORIES=	sysutils

MAINTAINER=	antranigv@FreeBSD.am
COMMENT=	Combines the functionality of watch and cat

LICENSE=	GPLv2

BUILD_DEPENDS=	voc:lang/voc

USE_GITHUB=	yes
GH_ACCOUNT=	norayr
GH_TAGNAME=	f1134a59f6b581d8d500b2678407285a1ee6443b

GH_TUPLE=	norayr:pipes:ef0629a71853b145def2b8b27300d3d02b228739:pipes/dps/pipes \
		norayr:strutils:2a450a1ef94a431787e258e262d053377ac9275c:strutils/dps/strutils \
		norayr:time:8f4d8612518cd69f91e85fa224c85bfe5d506028:time/dps/time

PLIST_FILES=	bin/watchcat

pre-build:
	${MKDIR} ${WRKSRC}/build/

do-build:
	(cd ${WRKSRC}/build && \
		${SETENVI} ${MAKE_ENV} voc \
		../dps/time/src/time.Mod -s \
		../dps/strutils/src/strTypes.Mod -s \
		../dps/strutils/src/strUtils.Mod -s \
		../dps/pipes/src/pipes.Mod -s \
		../src/watchcat.Mod -M \
	)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/watchcat ${STAGEDIR}${PREFIX}/bin/watchcat

.include <bsd.port.mk>
