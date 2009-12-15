# New ports collection makefile for:	docbook2X
# Date created:				23 Apr 2009
# Whom:					Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	docbook2X
PORTVERSION=	0.8.8
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Convert DocBook documents into UNIX man page and GNU Texinfo formats

BUILD_DEPENDS=	p5-XML-NamespaceSupport>=0:${PORTSDIR}/textproc/p5-XML-NamespaceSupport \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-SAX-Expat>=0:${PORTSDIR}/textproc/p5-XML-SAX-Expat \
		libxslt>=0:${PORTSDIR}/textproc/libxslt \
		sdocbook-xml>=0:${PORTSDIR}/textproc/sdocbook-xml \
		dsssl-docbook-modular>=0:${PORTSDIR}/textproc/dsssl-docbook-modular \
		OpenSP>=0:${PORTSDIR}/textproc/opensp
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	docbook-utils-*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_ICONV=	yes

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-doc__Makefile.in
.endif

post-patch:
		@${REINPLACE_CMD} "s|\$${prefix}|${PREFIX}|" \
			${WRKSRC}/configure

MAN1=		db2x_manxml.1 \
		db2x_texixml.1 \
		db2x_xsltproc.1 \
		docbook2man.1 \
		docbook2texi.1 \
		sgml2xml-isoent.1 \
		utf8trans.1

INFO=		docbook2X \
		docbook2man-xslt \
		docbook2texi-xslt

.include <bsd.port.mk>
