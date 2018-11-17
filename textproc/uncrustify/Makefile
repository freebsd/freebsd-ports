# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	uncrustify
PORTVERSION=	0.68
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	textproc

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Highly configurable source code beautifier

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=		fails to compile: cc1plus: error: unrecognized command line option "-std=gnu++0x"
BROKEN_mips64=		fails to compile: cc1plus: error: unrecognized command line option "-std=gnu++0x"
BROKEN_powerpc64=	fails to compile: cc1plus: error: unrecognized command line option "-std=gnu++0x"

USE_GITHUB=	yes

USES=		cmake:outsource
CMAKE_ARGS=	-DNoGitVersionString:BOOL=TRUE
TEST_TARGET=	test

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/*.cfg ${STAGEDIR}${ETCDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
