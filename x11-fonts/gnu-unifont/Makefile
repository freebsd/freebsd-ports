# $FreeBSD$

PORTNAME=	gnu-unifont
PORTVERSION=	7.0.03
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	GNU/unifont/unifont-${PORTVERSION}
DISTNAME=	unifont-${PORTVERSION}.pcf
EXTRACT_SUFX=	.gz
EXTRACT_ONLY=

MAINTAINER=	bsdports@gmail.com
COMMENT=	Unicode Font

USES=		fonts

NO_BUILD=	yes
PLIST_FILES=	${FONTSDIR}/unifont.pcf.gz

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${FONTSDIR}/unifont.pcf.gz

.include <bsd.port.mk>
