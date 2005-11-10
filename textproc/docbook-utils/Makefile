# New ports collection makefile for:	docbook-utils
# Date created:				3 May 2004
# Whom:					Brian Candler <B.Candler@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	docbook-utils
PORTVERSION=	0.6.14
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	docbook-tools/new-trials/SOURCES

MAINTAINER=	B.Candler@pobox.com
COMMENT=	Generates various output formats from DocBook SGML documents

BUILD_DEPENDS+=	nsgmls:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/sgml/docbook/3.1/docbook.dtd:${PORTSDIR}/textproc/docbook-310 \
		${LOCALBASE}/share/sgml/docbook/dsssl:${PORTSDIR}/textproc/dsssl-docbook-modular
RUN_DEPENDS+=	${LOCALBASE}/share/texmf/tex/jadetex/dsssl.def:${PORTSDIR}/print/jadetex \
		sgmlspl:${PORTSDIR}/textproc/p5-SGMLSpm

USE_PERL5_RUN=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		jw.1 sgmldiff.1 docbook2man-spec.pl.1 docbook2texi-spec.pl.1
MAN7=		backend-spec.7 frontend-spec.7
MLINKS=		jw.1 docbook2dvi.1 \
		jw.1 docbook2html.1 \
		jw.1 docbook2man.1 \
		jw.1 docbook2pdf.1 \
		jw.1 docbook2ps.1 \
		jw.1 docbook2rtf.1 \
		jw.1 docbook2tex.1 \
		jw.1 docbook2texi.1 \
		jw.1 docbook2txt.1
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

pre-configure:
	${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
