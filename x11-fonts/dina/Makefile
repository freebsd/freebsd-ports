# $FreeBSD$

PORTNAME=	dina
PORTVERSION=	2.92
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	LOCAL/rakuco

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Monospace bitmap font, primarily aimed at programmers

LICENSE=	MIT

USES=		fonts
BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

BDFLIST=	Dina_i400-10.bdf Dina_i400-8.bdf Dina_i400-9.bdf \
		Dina_i700-10.bdf Dina_i700-8.bdf Dina_i700-9.bdf \
		Dina_r400-10.bdf Dina_r400-6.bdf Dina_r400-8.bdf \
		Dina_r400-9.bdf Dina_r700-10.bdf Dina_r700-8.bdf \
		Dina_r700-9.bdf

do-build:
.for BDF in ${BDFLIST}
	cd ${WRKSRC}/BDF && bdftopcf -t -o ${BDF:S/.bdf/.pcf/} ${BDF}
.endfor
	${GZIP_CMD} ${WRKSRC}/BDF/*.pcf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/BDF/*.pcf.gz ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
