# New ports collection makefile for:	Authen-Simple-Net
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Simple-Net
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple authentication via FTP, POP3, or SMTP

BUILD_DEPENDS=	${SITE_PERL}/Authen/Simple.pm:${PORTSDIR}/security/p5-Authen-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Authen::Simple::FTP.3 Authen::Simple::POP3.3 Authen::Simple::SMTP.3

PERL_MODBUILD=	5.8.0+

.include <bsd.port.mk>
