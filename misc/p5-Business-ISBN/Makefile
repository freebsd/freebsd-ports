# New ports collection makefile for:	Business::ISBN
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Business-ISBN
PORTVERSION=	2.05
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Work with International Standard Book Numbers

RUN_DEPENDS=	p5-Business-ISBN-Data>=20081020:${PORTSDIR}/misc/p5-Business-ISBN-Data

PERL_CONFIGURE=	yes

MAN3=		ISBN.3 ISBN10.3 ISBN13.3

PLIST_FILES=	${SITE_PERL_REL}/Business/ISBN.pm \
		${SITE_PERL_REL}/Business/ISBN10.pm \
		${SITE_PERL_REL}/Business/ISBN13.pm \
		${SITE_PERL_REL}/${PERL_ARCH}/auto/Business/ISBN/.packlist

OPTIONS=	BARCODE "Barcode support" off \
		XISBN "xISBN support" off

.include <bsd.port.pre.mk>

.if defined(WITH_BARCODE)
RUN_DEPENDS+=	p5-GD-Barcode>=0:${PORTSDIR}/graphics/p5-GD-Barcode
.endif

.if defined(WITH_XISBN)
RUN_DEPENDS+=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
.endif

.include <bsd.port.post.mk>
