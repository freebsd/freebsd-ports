# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgrep
PORTVERSION=	6.4.3
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Context-aware grep for source codes

LICENSE=	GPLv2

BUILD_DEPENDS=	ghc:lang/ghc \
		hs-ansi-terminal>=0.5:devel/hs-ansi-terminal \
		hs-cmdargs>=0.10:devel/hs-cmdargs \
		hs-dlist>=0.3:devel/hs-dlist \
		hs-regex-posix>=0.90:textproc/hs-regex-posix \
		hs-safe>=0.3:devel/hs-safe \
		hs-split>=0.2:devel/hs-split \
		hs-stm>=2.1:devel/hs-stm \
		hs-stringsearch>=0.3:textproc/hs-stringsearch \
		hs-unordered-containers>=0.1:devel/hs-unordered-containers

USE_GITHUB=	yes
GH_ACCOUNT=	awgn

USES=	gmake

do-build:
	cd ${WRKSRC}/src && ${GMAKE} cgrep

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cgrep ${STAGEDIR}${PREFIX}/bin/

	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cgreprc ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
