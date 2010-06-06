# New ports collection makefile for:	OpenOffice::OODoc
# Date created:		10 October 2009
# Whom:			meyser@xenet.de
#
# $FreeBSD$
#

PORTNAME=	OpenOffice-OODoc
PORTVERSION=	2.124
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	meyser@xenet.de
COMMENT=	The Perl Open OpenDocument Connector

RUN_DEPENDS=	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-XML-Twig>=0:${PORTSDIR}/textproc/p5-XML-Twig

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	--noprompt

MAN1=		odf2pod.1 odf_set_fields.1 odf_set_title.1 odfbuild.1 \
		odfextract.1 odffilesearch.1 odffindbasic.1 odfhighlight.1 \
		odfmetadoc.1 odfsearch.1 oodoc_test.1 text2odf.1 text2table.1
MAN3=		OpenOffice::OODoc.3 OpenOffice::OODoc::Document.3 \
		OpenOffice::OODoc::File.3 OpenOffice::OODoc::Image.3 \
		OpenOffice::OODoc::Intro.3 OpenOffice::OODoc::Manifest.3 \
		OpenOffice::OODoc::Meta.3 OpenOffice::OODoc::Styles.3 \
		OpenOffice::OODoc::Text.3 OpenOffice::OODoc::XPath.3

.include <bsd.port.mk>
