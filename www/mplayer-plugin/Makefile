# New ports collection makefile for:	mplayerplug-in
# Date Created:				20 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayerplug-in
PORTVERSION=	3.40
CATEGORIES=	www multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mplayerplug-in

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A Mozilla plugin for the MPlayer media player

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GECKO=	firefox mozilla seamonkey
PLUGINSFILES=	mplayerplug-in.so mplayerplug-in.xpt mplayerplug-in-wmp.so \
		mplayerplug-in-qt.so mplayerplug-in-rm.so \
		mplayerplug-in-gmp.so mplayerplug-in-wmp.xpt \
		mplayerplug-in-qt.xpt mplayerplug-in-rm.xpt \
		mplayerplug-in-gmp.xpt mplayerplug-in-dvx.so \
		mplayerplug-in-dvx.xpt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gmp
USE_GNOME=	gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include -DBSD" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|make|${GMAKE}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|mozilla-|${GECKO}-|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' \
		${WRKSRC}/Source/plugin-setup.cpp

do-install:
	${MKDIR} ${PREFIX}/lib/browser_plugins
.for moo in ${PLUGINSFILES}
	${INSTALL_DATA} ${WRKSRC}/${moo} ${PREFIX}/lib/browser_plugins
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
