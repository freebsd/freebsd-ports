# $FreeBSD$

PORTNAME=	fantasque-sans-mono
PORTVERSION=	1.7.2
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/belluzj/fantasque-sans/releases/download/v${PORTVERSION}/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Programming font, designed with functionality in mind

LICENSE=	OFL11

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		fonts

OPTIONS_DEFINE=	DOCS

# For `make makesum' to include all distfiles, it should be run with
# WITH="$(make -V OPTIONS_SINGLE_VARIANT)".

OPTIONS_SINGLE=	VARIANT
OPTIONS_SINGLE_VARIANT= NORMAL NOLOOPK LLINE LLINENOLOOPK

NORMAL_DESC=	Standard
NOLOOPK_DESC=	Nondescript K
LLINE_DESC=	Large line spacing
LLINENOLOOPK_DESC=	Large line spacing with Nondescript K

OPTIONS_DEFAULT=	NORMAL

NORMAL_DISTFILES=	FantasqueSansMono-Normal.tar.gz
NOLOOPK_DISTFILES=	FantasqueSansMono-NoLoopK.tar.gz
LLINE_DISTFILES=	FantasqueSansMono-LargeLineHeight.tar.gz
LLINENOLOOPK_DISTFILES=	FantasqueSansMono-LargeLineHeight-NoLoopK.tar.gz

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC}/OTF && \
		${INSTALL_DATA} *.otf ${STAGEDIR}${FONTSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
