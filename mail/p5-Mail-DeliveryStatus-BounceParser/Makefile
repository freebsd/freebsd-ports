# New ports collection makefile for:	p5-Mail-DeliveryStatus-BounceParser
# Date created:				Thu Mar 25 20:40:31 MSK 2004
# Whom:					Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	Mail-DeliveryStatus-BounceParser
PORTVERSION=	1.5.17
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	Perl extension to analyze bounce messages

RUN_DEPENDS=	${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Mail::DeliveryStatus::BounceParser.3

.include <bsd.port.mk>
