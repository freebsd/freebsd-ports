# Created by: Lars Eggert <lars.eggert@gmx.net>
# $FreeBSD$

PORTNAME=	Net-XMPP
PORTVERSION=	1.02.04
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAPATRICK
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}_${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Net::XMPP provides Perl Developer access to the XMPP protocol

BUILD_DEPENDS=	p5-Authen-SASL>=2.12:${PORTSDIR}/security/p5-Authen-SASL \
		p5-Digest-SHA1>=1.02:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-XML-Stream>=1.23.04:${PORTSDIR}/textproc/p5-XML-Stream
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-LWP-Online>=1.07:${PORTSDIR}/www/p5-LWP-Online \
		p5-YAML-Tiny>=1.41:${PORTSDIR}/textproc/p5-YAML-Tiny

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
