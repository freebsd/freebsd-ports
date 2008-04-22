# New ports collection makefile for:	jfbterm
# Date created:				Feb 23 2008
# Whom:					nrg milk <bsdports@gmail.com>
#
# $FreeBSD$

PORTNAME=	jfbterm
PORTVERSION=	0.5.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ac.auone-net.jp/~baba/jfbterm/ \
		http://chirashi-no-ura.net/files/
DISTNAME=	jfbterm-FreeBSD-0.5.0

MAINTAINER=	bsdports@gmail.com
COMMENT=	Multilanguage can be displayed on the console

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/local/unifont.pcf.gz:${PORTSDIR}/sysutils/gnu-unifont

ONLY_FOR_ARCHS=	i386
USE_ICONV=	yes
USE_GNOME=	pkgconfig
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		--mandir="${LOCALBASE}/man"

MAN1=	jfbterm.1
MAN5=	jfbterm.conf.5

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
