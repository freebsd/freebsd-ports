# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Apache-SessionX
PORTVERSION=	2.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extented persistence framework for session data

BUILD_DEPENDS=	p5-Apache-Session>=0:${PORTSDIR}/www/p5-Apache-Session
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Apache::SessionX.3 \
	Apache::SessionX::Generate::MD5.3

USES=		perl5
USE_PERL5=	configure
IS_INTERACTIVE=	yes

.include <bsd.port.mk>
