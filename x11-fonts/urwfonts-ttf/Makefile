# New ports collection makefile for:	urwfonts-ttf
# Date created:				18 February 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	urwfonts-ttf
PORTVERSION=	1.0.7b18
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.gnome.ru/fonts/urw/release/
DISTNAME=	urw-fonts-${PORTVERSION:S/b/pre/}-ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unicode TrueType fonts from URW extended by Valek Filippov

DISABLE_SIZE=	yes
NO_WRKSUBDIR=	yes

USE_BZIP2=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/X11/fonts/urwfonts-ttf
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${WRKSRC}/fonts.* ${PREFIX}/lib/X11/fonts/urwfonts-ttf
	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/README ${PREFIX}/lib/X11/fonts/urwfonts-ttf

post-install:
	@${CAT} ${PKGMESSAGE}
		
.include <bsd.port.mk>
