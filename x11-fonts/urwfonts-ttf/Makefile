# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urwfonts-ttf
PORTVERSION=	1.0.7b18
PORTREVISION=	8
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.izmiran.rssi.ru/pub/fonts/urw/
DISTNAME=	urw-fonts-${PORTVERSION:S/b/pre/}-ttf

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Unicode TrueType fonts from URW extended by Valek Filippov

LICENSE=	LGPL20

DISABLE_SIZE=	yes
NO_WRKSUBDIR=	yes

NO_ARCH=	yes
NO_BUILD=	yes
USES=		fonts tar:bzip2

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.* ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
