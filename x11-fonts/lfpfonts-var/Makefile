# $FreeBSD$

PORTNAME=	lfpfonts-var
PORTVERSION=	0.83
PORTREVISION=	5
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/xfonts/${PORTNAME}/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Variable width fonts from the Linux Font Project

WRKSRC=		${WRKDIR}/lfpfonts-var

NO_BUILD=	yes
USES=		fonts tar:bzip2

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/lfp-var/*.pcf.gz ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
