PORTNAME=	hevea
DISTVERSION=	2.38
CATEGORIES=	textproc
MASTER_SITES=	https://hevea.inria.fr/distri/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Quite complete and fast LaTeX to HTML translator
WWW=		https://hevea.inria.fr/ \
		https://github.com/maranget/hevea/

LICENSE=	QPL-1.0
LICENSE_NAME=	Q Public License 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_DISTFILES+=	${PORTNAME}-${DISTVERSION}-manual.pdf \
			${PORTNAME}-${DISTVERSION}-manual.tar.gz

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} bibhva esponja hacha hevea

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${DISTVERSION}-manual.pdf ${STAGEDIR}${DOCSDIR}
	${TAR} xvfz ${DISTDIR}/${PORTNAME}-${DISTVERSION}-manual.tar.gz -C ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${LN} -sfv ${PREFIX}/lib/hevea/hevea.sty ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
