# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bodr
PORTVERSION=	10
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chemistry data like element and isotope properties, atomic radii, etc

BUILD_DEPENDS=	xsltproc:textproc/libxslt

OPTIONS_DEFINE=	DOCS

USES=		gmake perl5 tar:bzip2
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL="${PERL}"

post-patch:
	@${REINPLACE_CMD} -e \
		'/pkgconfig/s|{datadir}|{prefix}/libdata|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
