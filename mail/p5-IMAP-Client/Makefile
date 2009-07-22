# New ports collection makefile for:	p5-IMAP-Client
# Date created:		2006-08-12
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	IMAP-Client
PORTVERSION=	0.13
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Advanced manipulation of IMAP services w/ referral support

RUN_DEPENDS=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/URI/imap.pm:${PORTSDIR}/mail/p5-URI-imap

PERL_CONFIGURE=	yes

MAN3=		IMAP::Client.3

.include <bsd.port.mk>
