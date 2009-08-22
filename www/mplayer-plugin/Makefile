# New ports collection makefile for:	mplayerplug-in
# Date Created:				20 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayerplug-in
PORTVERSION=	3.55
PORTREVISION=	3
CATEGORIES=	www multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A Mozilla plugin for the MPlayer media player

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GECKO=	firefox mozilla seamonkey libxul
USE_WEBPLUGINS=	gecko*
WEBPLUGINS_FILES=mplayerplug-in.so mplayerplug-in.xpt mplayerplug-in-wmp.so \
		mplayerplug-in-qt.so mplayerplug-in-rm.so \
		mplayerplug-in-gmp.so mplayerplug-in-wmp.xpt \
		mplayerplug-in-qt.xpt mplayerplug-in-rm.xpt \
		mplayerplug-in-gmp.xpt mplayerplug-in-dvx.so \
		mplayerplug-in-dvx.xpt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gmp
USE_GNOME=	gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DBSD" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GECKO_XPIDL="${XPIDL}"
USE_XORG=	x11 xpm xt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|make|${GMAKE}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/Source/plugin-setup.cpp

do-install:
	${MKDIR} ${WEBPLUGINS_DIR}
.for moo in ${WEBPLUGINS_FILES}
	${INSTALL_DATA} ${WRKSRC}/${moo} ${WEBPLUGINS_DIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.conf \
		${PREFIX}/etc/mplayerplug-in.conf.dist
	if [ ! -f ${PREFIX}/etc/mplayerplug-in.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.conf \
			${PREFIX}/etc/mplayerplug-in.conf ; \
	fi
	${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.types \
		${PREFIX}/etc/mplayerplug-in.types.dist
	if [ ! -f ${PREFIX}/etc/mplayerplug-in.types ]; then \
		${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.types \
			${PREFIX}/etc/mplayerplug-in.types ;\
	fi
	cd ${WRKSRC}/po && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} install

.include <bsd.port.post.mk>
