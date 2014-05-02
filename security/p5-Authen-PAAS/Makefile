# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Authen-PAAS
PORTVERSION=	1.1.1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Perl Authentication & Authorization Service

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Config-Record>=1.1.0:${PORTSDIR}/devel/p5-Config-Record \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
