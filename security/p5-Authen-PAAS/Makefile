# New ports collection makefile for:	p5-Authen-PAAS
# Date created:				22 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-PAAS
PORTVERSION=	1.1.1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl Authentication & Authorization Service

BUILD_DEPENDS=	p5-Config-Record>=1.1.0:${PORTSDIR}/devel/p5-Config-Record \
		p5-Log-Log4perl>0:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN1=	authen-paas-passwd.1
MAN3=	Authen::PAAS.3 \
	Authen::PAAS::BasicLoginModule.3 \
	Authen::PAAS::BasicUser.3 \
	Authen::PAAS::Callback.3 \
	Authen::PAAS::ConsoleCallback.3 \
	Authen::PAAS::Context.3 \
	Authen::PAAS::Credential.3 \
	Authen::PAAS::LoginModule.3 \
	Authen::PAAS::Principal.3 \
	Authen::PAAS::SimpleCallback.3 \
	Authen::PAAS::Subject.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
