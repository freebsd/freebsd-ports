# New ports collection makefile for:	Ogle KDE GUI
# Date created:         Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	okle
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	multimedia kde
MASTER_SITES=	http://okle.sourceforge.net/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A KDE frontend to the Ogle DVD player

BUILD_DEPENDS=	${LOCALBASE}/lib/ogle/libdvdcontrol.so.11:${PORTSDIR}/multimedia/ogle
RUN_DEPENDS=	ogle:${PORTSDIR}/multimedia/ogle

USE_AUTOTOOLS=	autoconf:259 libtool:15
USE_KDELIBS_VER=3
CONFIGURE_ARGS=	--with-ogle-dir=${LOCALBASE}/bin \
		--with-ogle-includes=${LOCALBASE}/include \
		--program-transform-name="s|,|,|" \
		--with-ogle-libs=${LOCALBASE}/lib/ogle

# location of okle ogle_gui
DVDP_UI=${PREFIX}/lib/okle/ogle_gui
OGLE=${LOCALBASE}/bin/ogle

pre-everything::
.ifndef(WITH_DVD_DEVICE)
	@${ECHO_MSG} '===> The default DVD device is /dev/acd0c'
	@${ECHO_MSG} "===> You can choose any DVD device at Ogle's command line"
	@${ECHO_MSG} '===> Define WITH_DVD_DEVICE if you want to change the default'
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

pre-configure:
	@cd ${WRKSRC} && ${AUTOCONF} && ${AUTOHEADER}

.include <bsd.port.pre.mk>

.ifdef(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/acd0c
.endif

post-patch:
# point to specific device
	@${REINPLACE_CMD} -e "s|\"/dev/dvd\"|\"${DEFAULT_DVD_DEVICE}\"|" \
		${WRKSRC}/src/okle_win.cpp
# do not use version names
	@${REINPLACE_CMD} -E -e 's|^(PACKAGE[[:space:]]+=).+$$|\1${PORTNAME}|' \
		${WRKSRC}/po/Makefile.in

.include <bsd.port.post.mk>
