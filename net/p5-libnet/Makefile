# New ports collection makefile for:    p5-libnet
# Date created:				2002/03/13
# Whom:					jesper
#
# $FreeBSD$
#

PORTNAME=	libnet
PORTVERSION=	1.10
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	jesper@FreeBSD.org

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::Time.3 \
		Net::NNTP.3 \
		Net::Domain.3 \
		Net::POP3.3 \
		Net::FTP.3 \
		Net::Cmd.3 \
		Net::SMTP.3 \
		Net::libnetFAQ.3 \
		Net::Netrc.3

.include <bsd.port.mk>
