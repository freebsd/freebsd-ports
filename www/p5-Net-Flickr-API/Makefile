# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	Net-Flickr-API
PORTVERSION=	1.7
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Base API class for Net::Flickr::* libraries

BUILD_DEPENDS=	p5-Config-Simple>=0:${PORTSDIR}/devel/p5-Config-Simple \
		p5-Flickr-API>=0:${PORTSDIR}/www/p5-Flickr-API \
		p5-Flickr-Upload>=0:${PORTSDIR}/www/p5-Flickr-Upload \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Net::Flickr::API.3

NO_STAGE=	yes
.include <bsd.port.mk>
