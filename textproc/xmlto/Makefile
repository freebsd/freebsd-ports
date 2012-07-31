# New ports collection makefile for:	xmlto
# Date created:		2003-06-05
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	xmlto
PORTVERSION=	0.0.25
CATEGORIES=	textproc
MASTER_SITES=	https://fedorahosted.org/releases/x/m/xmlto/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Front-end to an XSL toolchain

BUILD_DEPENDS=	${BASH_CMD}:${PORTSDIR}/shells/bash \
		${GETOPT_CMD}:${PORTSDIR}/misc/getopt \
		xmllint:${PORTSDIR}/textproc/libxml2 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${XSL_DIR}:${PORTSDIR}/textproc/docbook-xsl \
		paperconf:${PORTSDIR}/print/libpaper \
		w3m:${PORTSDIR}/www/w3m \
		${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_JOBS_UNSAFE=	yes

OPTIONS=	DBLATEX "Add dependency on Dblatex" OFF \
		FOP "Add dependency on FOP (needs Java)" OFF \
		PASSIVETEX "Add dependency on PassiveTeX" OFF

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	BASH=${BASH_CMD} GETOPT=${GETOPT_CMD} PDFXMLTEX=${PDFXMLTEX_CMD}

BASH_CMD=	${LOCALBASE}/bin/bash
GETOPT_CMD=	${LOCALBASE}/bin/getopt
XSL_DIR=	${LOCALBASE}/share/xsl/docbook
PDFXMLTEX_CMD=	${LOCALBASE}/bin/pdftex

MAN1=		xmlif.1 xmlto.1
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS THANKS
# these two documentation files do not convey information useful for
# the FreeBSD port at this time:
# PORTDOCS+=	FAQ README

.include <bsd.port.pre.mk>

.if defined(WITH_PASSIVETEX)
BUILD_DEPENDS+=	${LOCALBASE}/share/texmf-local/tex/passivetex/fotex.sty:${PORTSDIR}/print/passivetex
.endif

.if defined(WITH_FOP)
RUN_DEPENDS+=	fop>=0.90:${PORTSDIR}/textproc/fop
CONFIGURE_ARGS+=	--with-backend=fop
.endif

.if defined(WITH_DBLATEX)
RUN_DEPENDS+=	${LOCALBASE}/bin/dblatex:${PORTSDIR}/textproc/dblatex
.if !defined(WITH_FOP)
CONFIGURE_ARGS+=	--with-backend=dblatex
.endif
.endif

post-patch:
	# get rid of nonstandard "type" option -t:
	cd ${WRKSRC} && ${FIND} . -type f -exec ${REINPLACE_CMD} -i '' -e 's/type -t/which/;' '{}' '+'
	# get rid of GNU-make-ism (BSD make defines $< only in suffix rules)
	${REINPLACE_CMD} -e '/^GEN_MANPAGE/{s/\$$</$$>/;}' ${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
