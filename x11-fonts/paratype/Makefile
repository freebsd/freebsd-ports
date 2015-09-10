# Created by: Alexey Illarionov <littlesavage@rambler.ru>
# $FreeBSD$

PORTNAME=	paratype
PORTVERSION=	2.004
PORTREVISION=	6
CATEGORIES=	x11-fonts
MASTER_SITES=	http://paratype.0xdc.ru/
DISTFILES=	PTSansOFL-2.004.zip PTSerifOFL-1.000.zip PTMonoOFL-1.002_1.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ParaType font collection for the languages of Russia

LICENSE=	OFL11

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		fonts zip

FONTNAME=	ParaType
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
