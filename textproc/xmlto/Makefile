# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	xmlto
PORTVERSION=	0.0.25
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://fedorahosted.org/releases/x/m/xmlto/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Front-end to an XSL toolchain

LICENSE=	GPLv2

BUILD_DEPENDS=	${BASH_CMD}:${PORTSDIR}/shells/bash \
		${GETOPT_CMD}:${PORTSDIR}/misc/getopt \
		xmllint:${PORTSDIR}/textproc/libxml2 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${XSL_DIR}:${PORTSDIR}/textproc/docbook-xsl \
		paperconf:${PORTSDIR}/print/libpaper \
		w3m:${PORTSDIR}/www/w3m \
		${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
RUN_DEPENDS:=	${BUILD_DEPENDS}

# TODO: make this a group for PDF output?
OPTIONS_DEFINE=		DBLATEX FOP PASSIVETEX
DBLATEX_DESC=		Add dependency on Dblatex
FOP_DESC=		Add dependency on FOP (needs Java)
PASSIVETEX_DESC=	- BROKEN - Add dependency on PassiveTeX

USE_BZIP2=	yes
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
BUILD_DEPENDS+=	${LOCALBASE}/share/texmf-local/tex/passivetex/fotex.sty:${PORTSDIR}/print/passivetex
BROKEN=		the passivetex option is currently broken
.endif

.if ${PORT_OPTIONS:MFOP}
RUN_DEPENDS+=	fop>=0.90:${PORTSDIR}/textproc/fop
CONFIGURE_ARGS+=	--with-backend=fop
.endif

.if ${PORT_OPTIONS:MDBLATEX}
RUN_DEPENDS+=	${LOCALBASE}/bin/dblatex:${PORTSDIR}/textproc/dblatex
.if ! ${PORT_OPTIONS:MFOP}
CONFIGURE_ARGS+=	--with-backend=dblatex
.endif
.endif

post-patch:
	@# get rid of nonstandard "type" option -t:
	cd ${WRKSRC} && ${FIND} . -type f -exec ${REINPLACE_CMD} -i '' -e 's/type -t/which/;' '{}' '+'
	@# get rid of GNU-make-ism (BSD make defines $< only in suffix rules)
	${REINPLACE_CMD} -e '/^GEN_MANPAGE/{s/\$$</$$>/;}' ${WRKSRC}/Makefile.in

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
