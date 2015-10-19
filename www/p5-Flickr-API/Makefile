# Created by: ijliao
# $FreeBSD$

PORTNAME=	Flickr-API
PORTVERSION=	1.25
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the Flickr API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Message>=1.56:${PORTSDIR}/www/p5-HTTP-Message \
		p5-Net-OAuth>=0:${PORTSDIR}/net/p5-Net-OAuth \
		p5-URI>=1.18:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML-Simple>=0:${PORTSDIR}/textproc/p5-XML-LibXML-Simple \
		p5-XML-Parser-Lite-Tree>=0.06:${PORTSDIR}/textproc/p5-XML-Parser-Lite-Tree \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Script>=0:${PORTSDIR}/devel/p5-Test-Script

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
