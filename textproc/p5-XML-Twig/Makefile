# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-Twig
PORTVERSION=	3.44
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Process huge XML documents by chunks via a tree interface

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Tree>=3.13:${PORTSDIR}/www/p5-HTML-Tree \
		p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-CaptureOutput>=0:${PORTSDIR}/devel/p5-IO-CaptureOutput \
		p5-XML-Handler-YAWriter>=0:${PORTSDIR}/textproc/p5-XML-Handler-YAWriter \
		p5-XML-SAX-Writer>=0:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		p5-XML-Simple>=2:${PORTSDIR}/textproc/p5-XML-Simple

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	-y

.include <bsd.port.mk>
