# Created by: Manuel Giraud <manuel.giraud@gmail.com>
# $FreeBSD$

PORTNAME=	profont
PORTVERSION=	400
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://tobiasjung.name/downloadfile.php?file=profont-x11.zip?dummy/
DISTNAME=	${PORTNAME}-x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ultimate programming font

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fonts zip
NO_ARCH=	yes

do-build:
	${GZIP_CMD} ${WRKSRC}/*.pcf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
