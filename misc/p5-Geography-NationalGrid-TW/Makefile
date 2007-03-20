# New ports collection makefile for:	misc/p5-Geography-NationalGrid-TW
# Date created:				2007/03/20
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Geography-NationalGrid-TW
PORTVERSION=	0.03
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Geography
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Convert Taiwan Datum (TWD67/TM2, TWD97/TM2) to/from Latitude and Longitude

BUILD_DEPENDS=	p5-Geography-NationalGrid>=0:${PORTSDIR}/misc/p5-Geography-NationalGrid
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Geography::NationalGrid::TW.3

.include <bsd.port.mk>
