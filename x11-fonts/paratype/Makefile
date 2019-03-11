# Created by: Alexey Illarionov <littlesavage@rambler.ru>
# $FreeBSD$

PORTNAME=	paratype
PORTVERSION=	2.005
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.paratype.com/uni/public/
DISTFILES=	PTSans.zip PTSerif.zip PTMono.zip

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
