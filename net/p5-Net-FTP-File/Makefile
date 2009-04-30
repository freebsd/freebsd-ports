# New ports collection makefile for:	p5-Net-FTP-File
# Date created:				25 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FTP-File
PORTVERSION=	0.06
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perls@FreeBSD.org
COMMENT=	Perl extension for simplifying FTP file operations

BUILD_DEPENDS=	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Net::FTP::File.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
