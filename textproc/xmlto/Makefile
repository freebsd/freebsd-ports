# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	xmlto
PORTVERSION=	0.0.28
CATEGORIES=	textproc
MASTER_SITES=	https://fedorahosted.org/releases/x/m/xmlto/:xmlto \
		LOCAL/mandree/:xmlto \
		http://www.antennahouse.com/XSLsample/sample-xsl-xhtml2fo/:xsl \
		LOCAL/mandree/:xsl
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:xmlto \
		xhtml2fo.xsl:xsl
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Front-end to an XSL toolchain

LICENSE=	GPLv2

BUILD_DEPENDS=	${BASH_CMD}:shells/bash \
		${GETOPT_CMD}:misc/getopt \
		xmllint:textproc/libxml2 \
		xsltproc:textproc/libxslt \
		docbook-xsl>0:textproc/docbook-xsl \
		paperconf:print/libpaper \
		w3m:www/w3m \
		docbook-xml>0:textproc/docbook-xml
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS
OPTIONS_GROUP=		BACKEND
OPTIONS_GROUP_BACKEND=		DBLATEX FOP PASSIVETEX
BACKEND_DESC=		Postprocessor backends to enable
DBLATEX_DESC=		Add dependency on DBlatex (DB for DocBook)
FOP_DESC=		Add dependency on FOP (requires Java)
PASSIVETEX_DESC=	Add dependency on XMLTeX/PassiveTeX

USES=		tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	BASH=${BASH_CMD} GETOPT=${GETOPT_CMD} PDFXMLTEX=${PDFXMLTEX_CMD}
MAKE_ENV+=	HOME=/dev/null

BASH_CMD=	${LOCALBASE}/bin/bash
GETOPT_CMD=	${LOCALBASE}/bin/getopt
XSL_DIR=	${LOCALBASE}/share/xsl/docbook
PDFXMLTEX_CMD=	${LOCALBASE}/bin/pdftex

PORTDOCS=	AUTHORS ChangeLog NEWS THANKS
# these documentation files do not convey information useful for
# the FreeBSD port at this time, or are provided by the ports framework:
# PORTDOCS+=	COPYING FAQ README

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPASSIVETEX}
USE_TEX+=	xmltex
.endif

.if ${PORT_OPTIONS:MFOP}
RUN_DEPENDS+=	fop>=0.90:textproc/fop
CONFIGURE_ARGS+=	--with-backend=fop
.endif

.if ${PORT_OPTIONS:MDBLATEX}
RUN_DEPENDS+=	${LOCALBASE}/bin/dblatex:textproc/dblatex
.if ! ${PORT_OPTIONS:MFOP}
CONFIGURE_ARGS+=	--with-backend=dblatex
.endif
.endif

post-patch:
	@# get rid of nonstandard "type" option -t:
	${SED} -i '' -e 's/type -t/which/;' \
		${WRKSRC}/format/docbook/epub \
		${WRKSRC}/format/docbook/txt \
		${WRKSRC}/format/fo/dvi \
		${WRKSRC}/format/fo/pdf \
		${WRKSRC}/format/xhtml1/txt
	@# get rid of GNU-make-ism (BSD make defines $< only in suffix rules)
	${REINPLACE_CMD} -e '/^GEN_MANPAGE/{s/\$$</$$>/;}' ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/xhtml2fo.xsl ${STAGEDIR}${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
