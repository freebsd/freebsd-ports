PORTNAME=	uncrustify
PORTVERSION=	0.82.0
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	textproc

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Highly configurable source code beautifier
WWW=		https://uncrustify.sourceforge.net/ \
		https://github.com/uncrustify/uncrustify

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes

USES=		cmake compiler:c++11-lang python:build
CMAKE_ON=	NoGitVersionString
TEST_TARGET=	test

PORTSCOUT=	limit:^[0-9]+\.

PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_FILES=	bin/uncrustify share/man/man1/uncrustify.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
