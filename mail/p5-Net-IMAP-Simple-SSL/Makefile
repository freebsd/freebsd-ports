# New ports collection makefile for:	mail/p5-Net-IMAP-Simple-SSL
# Date created:				30 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IMAP-Simple-SSL
PORTVERSION=	1.3
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	SSL support for Net::IMAP::Simple

BUILD_DEPENDS=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/Net/IMAP/Simple.pm:${PORTSDIR}/mail/p5-Net-IMAP-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::IMAP::Simple::SSL.3

.include <bsd.port.mk>
