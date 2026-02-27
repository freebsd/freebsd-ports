PORTNAME=	oyo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.24
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Step-through diff viewer
WWW=		https://github.com/ahkohd/oyo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ahkohd

CARGO_INSTALL_PATH=	crates/oyo

OPTIONS_DEFINE=	DOCS

post-patch-DOCS-on:
	${REINPLACE_CMD} -e 's|\.\./\(assets/\)|${DOCSDIR}/\1|g' ${WRKSRC}/docs/*.md

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/assets
	(cd ${WRKSRC}/docs && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name *\.bak" && \
	${COPYTREE_SHARE} ../assets ${STAGEDIR}${DOCSDIR}/assets)

.include <bsd.port.mk>
