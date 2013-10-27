# Created by: Dima Sivachenko <dima@chg.ru>
# $FreeBSD$

PORTNAME=	xnc
PORTVERSION=	5.0.4
PORTREVISION=	8
CATEGORIES=	x11-fm
MASTER_SITES=	# http://www.xnc.dubna.su/src-5/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File manager for X11 similar to Norton Commander

LICENSE=	GPLv2

NO_STAGE=	yes
# xnc will use the following programs if you have them installed:
#RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
#		unzip:${PORTSDIR}/archivers/unzip \
#		rpm:${PORTSDIR}/archivers/rpm \
#		rar:${PORTSDIR}/archivers/rar \
#		unarj:${PORTSDIR}/archivers/unarj \
#		lha:${PORTSDIR}/archivers/lha
LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

USES=		gettext
GNU_CONFIGURE=	yes
USE_XORG=	x11 xext xt
CONFIGURE_ARGS=	--with-pty=BSD --with-libintl-prefix=${LOCALBASE}
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		ives.1 xjpegroot.1 xnc.1 xnlaunch.1 iedit.1 iview.1

post-patch:
	@${REINPLACE_CMD} -e 's|make |$$(MAKE) |' \
		${WRKSRC}/src/launch/makefile.in \
		${WRKSRC}/src/plugins/aqua/makefile.in \
		${WRKSRC}/src/plugins/five/makefile.in \
		${WRKSRC}/src/plugins/theme/makefile.in \
		${WRKSRC}/src/xjroot/makefile.in \
		${WRKSRC}/src/xsetup/makefile.in

post-configure:
	@${REINPLACE_CMD} -e 's|-I$$(MYSRCDIR)/intl|| ; \
		s|$${top_builddir}/intl/libintl.a|-lintl|' \
			${WRKSRC}/src/ives/makefile \
			${WRKSRC}/src/launch/makefile \
			${WRKSRC}/src/xsetup/makefile \
			${WRKSRC}/src/makefile

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
