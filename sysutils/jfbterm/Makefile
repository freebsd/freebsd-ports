# New ports collection makefile for:	jfbterm
# Date created:				Feb 23 2008
# Whom:					nrg milk <bsdports@gmail.com>
#
# $FreeBSD$

PORTNAME=	jfbterm
PORTVERSION=	0.6.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ac.auone-net.jp/~baba/jfbterm/ \
		http://chirashi-no-ura.net/files/
DISTNAME=	${PORTNAME}-FreeBSD-${PORTVERSION}

MAINTAINER=	bsdports@gmail.com
COMMENT=	Multilanguage can be displayed on the console

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/local/unifont.pcf.gz:${PORTSDIR}/x11-fonts/gnu-unifont

USE_ICONV=	yes
USE_GNOME=	pkgconfig
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262 automake:14
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		--mandir="${LOCALBASE}/man"

MAN1=	jfbterm.1
MAN5=	jfbterm.conf.5

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
