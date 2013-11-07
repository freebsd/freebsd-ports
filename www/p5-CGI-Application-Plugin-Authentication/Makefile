# Created by: George Hartzell <hartzell@alerce.com>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-Authentication
PORTVERSION=	0.20
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Support for authenticating requests in CGI::Application

BUILD_DEPENDS=	p5-Apache-Htpasswd>=0:${PORTSDIR}/security/p5-Apache-Htpasswd \
		p5-CGI-Application>=4:${PORTSDIR}/www/p5-CGI-Application \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Color-Calc>=1.073:${PORTSDIR}/graphics/p5-Color-Calc
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Warn>=0.11:${PORTSDIR}/devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
