# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bodr
PORTVERSION=	9
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chemistry data like element and isotope properties, atomic radii, etc

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USES=		perl5
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	build
GNU_CONFIGURE=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|{datadir}/pkgconfig|{prefix}/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
