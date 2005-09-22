# New ports collection makefile for:	Business::ISBN
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		Business-ISBN
PORTVERSION=		1.82
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Business
PKGNAMEPREFIX=		p5-

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Work with International Standard Book Numbers

BUILD_DEPENDS=		${SITE_PERL}/Business/ISBN/Data.pm:${PORTSDIR}/misc/p5-Business-ISBN-Data
RUN_DEPENDS=		${BUILD_DEPENDS}

PERL_CONFIGURE=		yes

MAN3=			Business::ISBN.3

PLIST_FILES=		${SITE_PERL_REL}/Business/ISBN.pm \
			${SITE_PERL_REL}/${PERL_ARCH}/auto/Business/ISBN/.packlist

.include <bsd.port.mk>
