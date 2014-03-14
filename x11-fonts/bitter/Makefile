# $FreeBSD$

PORTNAME=	bitter
PORTVERSION=	20130930
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.huertatipografica.com/free_download/eo0pZGbJPxy2YyRkWQXx?dummy=

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Contemporary serif typeface for text designed for comfortably reading

LICENSE=	OFL11

FETCH_BEFORE_ARGS=	-o ${DISTFILES}

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTDIR=	${STAGEDIR}${PREFIX}/lib/X11/fonts/${PORTNAME}

do-install:
	${MKDIR} ${FONTDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} *.otf ${FONTDIR}

.include <bsd.port.mk>
