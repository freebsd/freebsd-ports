# New ports collection makefile for:	p5-Net-FTP-File
# Date created:				25 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FTP-File
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for simplifying FTP file operations

MAN3=	Net::FTP::File.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
BUILD_DEPENDS+=	p5-Net>=0:${PORTSDIR}/net/p5-Net
RUN_DEPENDS+=	p5-Net>=0:${PORTSDIR}/net/p5-Net
.endif

.include <bsd.port.post.mk>
