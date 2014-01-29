# Created by: nrg milk <bsdports@gmail.com>
# $FreeBSD$

PORTNAME=	gnu-unifont-ttf
PORTVERSION=	20131020
CATEGORIES=	x11-fonts
MASTER_SITES=	http://unifoundry.com/pub/unifont-6.3.${PORTVERSION}/font-builds/
DISTNAME=	unifont-6.3.${PORTVERSION}.ttf
EXTRACT_SUFX=	.gz

MAINTAINER=	bsdports@gmail.com
COMMENT=	Unicode TrueType Font

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	> ${WRKDIR}/${DISTNAME}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	lib/X11/fonts/local/unifont.ttf

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/lib/X11/fonts/local/unifont.ttf

.include <bsd.port.mk>
