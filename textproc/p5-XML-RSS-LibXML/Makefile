# New ports collection makefile for:	p5-XML-RSS-LibXML
# Date created:		2006-01-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RSS-LibXML
PORTVERSION=	0.31.00
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	XML::RSS with XML::LibXML

RUN_DEPENDS=	p5-XML-LibXML>=1.66:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/DateTime/Format/Mail.pm:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
		${SITE_PERL}/DateTime/Format/W3CDTF.pm:${PORTSDIR}/devel/p5-DateTime-Format-W3CDTF \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.7.3+	# inherited from converters/p5-Encode

MAN3=		XML::RSS::LibXML.3 XML::RSS::LibXML::ImplBase.3 \
		XML::RSS::LibXML::MagicElement.3 \
		XML::RSS::LibXML::Namespaces.3

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/benchmark.pl ${EXAMPLESDIR}

.include <bsd.port.mk>
