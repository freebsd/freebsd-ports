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
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Caches mail information for Mail::IMAPTalk using Mail::Cache

BUILD_DEPENDS=	p5-Mail-Cache>=0:${PORTSDIR}/mail/p5-Mail-Cache \
		p5-Mail-IMAPTalk>=0:${PORTSDIR}/mail/p5-Mail-IMAPTalk

PERL_CONFIGURE=	yes

MAN3=		Mail::IMAPTalk::MailCache.3

.include <bsd.port.mk>
