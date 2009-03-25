# New ports collection makefile for:	Authen-DecHpwd
# Date created:				01 Jun 2008
# Whom:					brix@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Authen-DecHpwd
PORTVERSION=	2.004
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Perl module for DEC VMS password hashing

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/String.pm:${PORTSDIR}/devel/p5-Scalar-String \
		${SITE_PERL}/Data/Integer.pm:${PORTSDIR}/devel/p5-Data-Integer
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Authen::DecHpwd.3

.include <bsd.port.mk>
