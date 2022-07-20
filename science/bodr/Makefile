PORTNAME=	bodr
PORTVERSION=	10
CATEGORIES=	science
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chemistry data like element and isotope properties, atomic radii, etc

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xsltproc:textproc/libxslt

USES=		gmake perl5 tar:bzip2
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL="${PERL}"
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/pkgconfig/s|{datadir}|{prefix}/libdata|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
