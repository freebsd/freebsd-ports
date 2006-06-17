# New ports collection makefile for:	p5-Mail-DeliveryStatus-BounceParser
# Date created:				Thu Mar 25 20:40:31 MSK 2004
# Whom:					Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	Mail-DeliveryStatus-BounceParser
PORTVERSION=	1.5.11
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-1.511

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	Perl extension to analyze bounce messages

BUILD_DEPENDS=	${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::DeliveryStatus::BounceParser.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600 # inherited from mail/p5-MIME-Tools
IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
