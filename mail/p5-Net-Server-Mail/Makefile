# New ports collection makefile for:	p5-Net-Server-Mail
# Date created:				6th February 2004
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Server-Mail
PORTVERSION=	0.08
CATEGORIES=	mail perl5
MASTER_SITES=	ftp://ftp.rhapsodyk.net/pub/devel/perl/Net-Server-Mail/
PKGNAMEPREFIX=	p5-

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Implementation of SMTP, ESMTP and LMTP protocols

RUN_DEPENDS=	${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net

PERL_CONFIGURE=	yes

MAN3=		Net::Server::Mail.3 \
		Net::Server::Mail::ESMTP.3 \
		Net::Server::Mail::ESMTP::Extension.3 \
		Net::Server::Mail::LMTP.3 \
		Net::Server::Mail::SMTP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		This port needs Perl 5.006 or greater, please upgrade your Perl
.endif

.include <bsd.port.post.mk>
