# Created by: Lars Eggert <lars.eggert@gmx.net>
# $FreeBSD$

PORTNAME=	Net-XMPP
DISTVERSION=	1.05
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:DAPATRICK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Net::XMPP provides Perl Developer access to the XMPP protocol

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-Authen-SASL>=2.12:security/p5-Authen-SASL \
		p5-Digest-SHA>=5.95:security/p5-Digest-SHA \
		p5-XML-Stream>=1.24:textproc/p5-XML-Stream
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-LWP-Online>=1.07:www/p5-LWP-Online \
		p5-YAML-Tiny>=1.41:textproc/p5-YAML-Tiny

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
