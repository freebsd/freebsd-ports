# New ports collection makefile for:	xnc
# Date created:		5 February 1999
# Whom:			Dima Sivachenko	<dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	xnc
PORTVERSION=	5.0.4
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.xnc.dubna.su/src-5/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	demon@FreeBSD.org
COMMENT=	File manager for X Window

# xnc will use the following programs if you have them installed.
#RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip		\
#		unzip:${PORTSDIR}/archivers/unzip	\
#		rpm:${PORTSDIR}/archivers/rpm		\
#		rar:${PORTSDIR}/archivers/rar		\
#		unarj:${PORTSDIR}/archivers/unarj	\
#		lha:${PORTSDIR}/archivers/lha
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GETTEXT=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pty=BSD --with-libintl-prefix=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		ives.1 xjpegroot.1 xnc.1 xnlaunch.1 iedit.1 iview.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
