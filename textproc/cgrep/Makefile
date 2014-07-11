# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgrep
PORTVERSION=	6.4.3
CATEGORIES=	textproc

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Context-aware grep for source codes

LICENSE=	GPLv2

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-ansi-terminal>=0.5:${PORTSDIR}/devel/hs-ansi-terminal \
		hs-cmdargs>=0.10:${PORTSDIR}/devel/hs-cmdargs \
		hs-dlist>=0.3:${PORTSDIR}/devel/hs-dlist \
		hs-regex-posix>=0.90:${PORTSDIR}/textproc/hs-regex-posix \
		hs-safe>=0.3:${PORTSDIR}/devel/hs-safe \
		hs-split>=0.2:${PORTSDIR}/devel/hs-split \
		hs-stm>=2.1:${PORTSDIR}/devel/hs-stm \
		hs-stringsearch>=0.3:${PORTSDIR}/textproc/hs-stringsearch \
		hs-unordered-containers>=0.1:${PORTSDIR}/devel/hs-unordered-containers

USE_GITHUB=	yes
GH_ACCOUNT=	awgn
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	0ade66d

USES=	gmake

do-build:
	cd ${WRKSRC}/src && ${GMAKE} cgrep

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cgrep ${STAGEDIR}${PREFIX}/bin/

	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cgreprc ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
