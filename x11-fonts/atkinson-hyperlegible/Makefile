PORTNAME=	atkinson-hyperlegible
PORTVERSION=	2020.0514
PORTREVISION=	1
CATEGORIES=	x11-fonts accessibility
MASTER_SITES=	https://brailleinstitute.org/wp-content/uploads/${PORTNAME}-font/:source1 \
		http://brailleinstitute.org/wp-content/uploads/2020/11/:source2
DISTFILES=	${AHF}-Print-and-Web-${PORTVERSION:S/./-/}.zip:source1 \
		${AHF}-License-2020-1104.pdf:source2
EXTRACT_ONLY=	${AHF}-Print-and-Web-${PORTVERSION:S/./-/}.zip

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Braille Institute font for low vision readers
WWW=		https://brailleinstitute.org/freefont

LICENSE=	ATKINSON-HYPERLEGIBLE
LICENSE_NAME=	ATKINSON HYPERLEGIBLE FONT LICENSE
LICENSE_FILE=	${DISTDIR}/${AHF}-License-2020-1104.pdf
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		fonts zip

OPTIONS_DEFINE=		OTF TTF WEB
OPTIONS_DEFAULT=	OTF TTF
OTF_DESC=		Install OTF fonts set
TTF_DESC=		Install TTF fonts set
WEB_DESC=		Install WEB fonts set

AHF=		Atkinson-Hyperlegible-Font

OPTIONS_SUB=	yes
SUB_FILES=	pkg-message
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${AHF}-Print-and-Web-${PORTVERSION:S/./-/}

.include <bsd.port.options.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/allfonts
	@${FIND} ${WRKSRC} -type f -exec ${MV} {} ${WRKSRC}/allfonts \;

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}

do-install-TTF-on:
	${INSTALL_DATA} ${WRKSRC}/allfonts/*.ttf ${STAGEDIR}${FONTSDIR}

do-install-OTF-on:
	${INSTALL_DATA} ${WRKSRC}/allfonts/*.otf ${STAGEDIR}${FONTSDIR}

post-install-WEB-on:
.for ext in svg eot woff woff2
	${INSTALL_DATA} ${WRKSRC}/allfonts/*.${ext} ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>
