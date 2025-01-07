PORTNAME=	hevea
PORTVERSION=	2.36
CATEGORIES=	textproc
MASTER_SITES=	http://moscova.inria.fr/~maranget/${PORTNAME}/distri/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert LaTeX to HTML
WWW=		http://para.inria.fr/~maranget/hevea/

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

PLIST_SUB=	HEVEAVERSION=${PORTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES+=	${PORTNAME}-${PORTVERSION}-manual.pdf \
			${PORTNAME}-${PORTVERSION}-manual.tar.gz

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/esponja
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bibhva
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hevea
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hacha

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/hevea
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-manual.pdf ${STAGEDIR}${PREFIX}/share/doc/hevea
	(cd ${STAGEDIR}${PREFIX}/share/doc/hevea; ${TAR} xvfz ${DISTDIR}/${PORTNAME}-${PORTVERSION}-manual.tar.gz)

.include <bsd.port.mk>
