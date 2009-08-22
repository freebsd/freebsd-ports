# New ports collection makefile for:	bodr
# Date created:				21 May 2007
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	bodr
PORTVERSION=	8
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Chemistry data like element and isotope properties, atomic radii, etc

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|{datadir}/pkgconfig|{prefix}/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
