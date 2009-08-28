# New ports collection makefile for:	misc/p5-Geography-NationalGrid-TW
# Date created:				2007/03/20
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Geography-NationalGrid-TW
PORTVERSION=	0.06
CATEGORIES=	misc perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert Taiwan Datum (TWD67/TM2, TWD97/TM2) to/from Lat and Long

BUILD_DEPENDS=	p5-Geography-NationalGrid>=0:${PORTSDIR}/misc/p5-Geography-NationalGrid
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Geography::NationalGrid::TW.3

.include <bsd.port.mk>
