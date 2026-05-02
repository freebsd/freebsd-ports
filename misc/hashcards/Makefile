PORTNAME=	hashcards
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	misc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Plain text-based spaced repetition system
WWW=		https://github.com/eudoxia0/hashcards/

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE CDLA20 ISCL MIT OpenSSL UNICODE \
		UNLICENSE ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_CDLA20=	Community Data License Agreement – Permissive, Version 2.0
LICENSE_NAME_UNICODE=	Unicode Terms of Use
LICENSE_TEXT_CDLA20=	See https://cdla.dev/permissive-2-0/
LICENSE_TEXT_UNICODE=	See https://spdx.org/licenses/Unicode-TOU.html
LICENSE_PERMS_CDLA20=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	eudoxia0

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/example && \
	${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} "! -name .gitignore")

.include <bsd.port.mk>
