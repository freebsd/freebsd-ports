# Created by: ijliao
# $FreeBSD$

PORTNAME=	WWW-Mediawiki-Client
PORTVERSION=	0.31
PORTREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Very simple cvs-like interface for Mediawiki websites

BUILD_DEPENDS=	p5-VCS-Lite>0:devel/p5-VCS-Lite \
		p5-libwww>0:www/p5-libwww \
		p5-HTML-Parser>0:www/p5-HTML-Parser \
		p5-XML-LibXML>0:textproc/p5-XML-LibXML \
		p5-URI>=1.31:net/p5-URI \
		p5-Exception-Class>0:devel/p5-Exception-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>0:devel/p5-Test-Differences

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
