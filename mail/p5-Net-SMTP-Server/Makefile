# New ports collection makefile for:   p5-Net-SMTP-Server
# Date created:                22 March 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	Net-SMTP-Server
PORTVERSION=	1.1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-
DISTNAME=	SMTP-Server-${PORTVERSION}

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	A native Perl SMTP Server

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS=	${BUILD_DEPENDS}

MASTER_SITE_BACKUP+=	http://www.macgyver.org/software/perl/

PERL_CONFIGURE=	yes

MAN3=		Net::SMTP::Server.3 \
		Net::SMTP::Server::Client.3 \
		Net::SMTP::Server::Relay.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS+=	${SITE_PERL}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net
.endif

.include <bsd.port.post.mk>
