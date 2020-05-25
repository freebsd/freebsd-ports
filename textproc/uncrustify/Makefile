# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	uncrustify
PORTVERSION=	0.71.0
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	textproc

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Highly configurable source code beautifier

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes

USES=		cmake compiler:c++11-lang
CMAKE_ARGS=	-DNoGitVersionString:BOOL=TRUE
TEST_TARGET=	test

PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_FILES=	bin/uncrustify man/man1/uncrustify.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

# fixes build on gcc archs (unrecognized command line option
# -std=gnu++0x), but may introduce other errors in future
post-patch:
	@${REINPLACE_CMD} -e '/gnu++0x/ d' ${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
