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

MAINTAINER=	erwin@lansing.dk

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/SMTP.pm:${PORTSDIR}/net/p5-Net \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS

MASTER_SITE_BACKUP+=	http://www.macgyver.org/software/perl/

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::SMTP::Server.3 \
		Net::SMTP::Server::Client.3 \
		Net::SMTP::Server::Relay.3

.include <bsd.port.mk>
