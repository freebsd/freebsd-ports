# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urwfonts-ttf
PORTVERSION=	1.0.7b18
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.izmiran.rssi.ru/pub/fonts/urw/
DISTNAME=	urw-fonts-${PORTVERSION:S/b/pre/}-ttf

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Unicode TrueType fonts from URW extended by Valek Filippov

LICENSE=	LGPL20

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

DISABLE_SIZE=	yes
NO_WRKSUBDIR=	yes

NO_BUILD=	yes
USES=		tar:bzip2

FONTDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

do-install:
	@${MKDIR} ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.* ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
