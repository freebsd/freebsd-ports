# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	uncrustify
PORTVERSION=	0.68.1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	textproc

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Highly configurable source code beautifier

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_TAGNAME=	dbe32c0

USES=		cmake compiler:c++11-lang
CMAKE_ARGS=	-DNoGitVersionString:BOOL=TRUE
TEST_TARGET=	test

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

# fixes BROKENs above, but may introduce different errors
post-patch:
	@${REINPLACE_CMD} -e '/gnu++0x/ d' ${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/*.cfg ${STAGEDIR}${ETCDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
