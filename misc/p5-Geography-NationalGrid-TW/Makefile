# New ports collection makefile for:	misc/p5-Geography-NationalGrid-TW
# Date created:				2007/03/20
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Geography-NationalGrid-TW
PORTVERSION=	0.08
CATEGORIES=	misc perl5 geography
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEEYM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert Taiwan Datum (TWD67/TM2, TWD97/TM2) to/from Lat and Long

DEPRECATED=	Depends on misc/p5-Geography-NationalGrid, which is DEPRECATED
EXPIRATION_DATE=	2011-10-31

BUILD_DEPENDS=	p5-Geography-NationalGrid>=0:${PORTSDIR}/misc/p5-Geography-NationalGrid
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Geography::NationalGrid::TW.3

.include <bsd.port.mk>
