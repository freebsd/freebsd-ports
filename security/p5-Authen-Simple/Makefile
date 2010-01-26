# New ports collection makefile for:	Authen-Simple
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Simple
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple authentication framework

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Crypt/PasswdMD5.pm:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA.pm:${PORTSDIR}/security/p5-Digest-SHA \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Authen::Simple.3 \
	Authen::Simple::Adapter.3 \
	Authen::Simple::Apache.3 \
	Authen::Simple::Log.3 \
	Authen::Simple::Password.3

PERL_MODBUILD=	5.8.0+

.include <bsd.port.mk>
