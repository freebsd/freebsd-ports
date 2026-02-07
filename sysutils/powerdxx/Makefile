PORTNAME=	powerdxx
DISTVERSION=	0.4.4
PORTREVISION=	3
CATEGORIES=	sysutils
PATCH_SITES=	https://github.com/lonkamikaze/powerdxx/commit/
PATCHFILES=	026a0c4a922f5a4aa289959940e7b9eea18a7663.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CPU clock speed/frequency daemon
WWW=		https://github.com/lonkamikaze/powerdxx

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	lonkamikaze
GH_TUPLE=	lonkamikaze:powerdxx:c555acd:powerdxx/gh-pages

USE_LDCONFIG=	yes
MAKE_ARGS=	DOCSDIR="${DOCSDIR}"

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/gh-pages/refman.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
