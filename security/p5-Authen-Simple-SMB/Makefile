# New ports collection makefile for:	Authen-Simple-SMB
# Date created:				22 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Simple-SMB
PORTVERSION=	0.1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Simple SMB authentication

BUILD_DEPENDS=	${SITE_PERL}/Authen/Simple.pm:${PORTSDIR}/security/p5-Authen-Simple \
		${SITE_PERL}/${PERL_ARCH}/Authen/Smb.pm:${PORTSDIR}/security/p5-Authen-Smb
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Authen::Simple::SMB.3

PERL_MODBUILD=	5.8.0+

.include <bsd.port.mk>
