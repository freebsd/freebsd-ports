# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	whitespace
PORTVERSION=	0.3
PORTREVISION=	7
CATEGORIES=	lang
MASTER_SITES=	http://compsoc.dur.ac.uk/whitespace/downloads/
DISTNAME=	wspace-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interpreter for the Whitespace programming language

LICENSE=	GPLv2

BUILD_DEPENDS=	ghc:lang/ghc
LIB_DEPENDS=	libgmp.so:math/gmp \
		libffi.so.6:devel/libffi

USES=		perl5 gmake tar:tgz
USE_PERL5=	build
WRKSRC=	${WRKDIR}/WSpace
ALL_TARGET=	${TARGET}

PLIST_FILES=	bin/wspace
PORTEXAMPLES=	*
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wspace ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
