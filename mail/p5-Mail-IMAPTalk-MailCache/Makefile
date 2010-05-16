# New ports collection makefile for:	p5-Mail-IMAPTalk-MailCache
# Date created:		2009-09-27
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Mail-IMAPTalk-MailCache
PORTVERSION=	0.0.1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Caches mail information for Mail::IMAPTalk using Mail::Cache.

BUILD_DEPENDS=	${SITE_PERL}/Mail/Cache.pm:${PORTSDIR}/mail/p5-Mail-Cache \
		${SITE_PERL}/Mail/IMAPTalk.pm:${PORTSDIR}/mail/p5-Mail-IMAPTalk

PERL_CONFIGURE=	yes

MAN3=		Mail::IMAPTalk::MailCache.3

.include <bsd.port.mk>
