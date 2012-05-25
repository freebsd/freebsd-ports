# New ports collection makefile for:	k9copy
# Date created:				19 Dec 2005
# Whom:			Alexander V. Ribchansky <triosoft@triosoft.com.ua>
#
# $FreeBSD$

PORTNAME=	k9copy
PORTVERSION=	1.2.4
CATEGORIES=	multimedia kde
MASTER_SITES=	SF

MAINTAINER=	triosoft@triosoft.com.ua
COMMENT=	A DVD-9 to DVD-5 shrinking application for KDE

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread \
		avcodec:${PORTSDIR}/multimedia/ffmpeg \
		hal:${PORTSDIR}/sysutils/hal \
		dbus:${PORTSDIR}/devel/dbus
RUN_DEPENDS=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		vamps:${PORTSDIR}/multimedia/vamps

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,,g ; \
		s,-lpthread,${PTHREAD_LIBS},g ; \
		s,/usr/local/lib/dbus-1.0/include,/usr/local/include/dbus-1.0/include,g' \
	       	${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's,$$(LIB_KDEUI),$$(LIB_KDEUI) $$(LIBPTHREAD) -lcam,g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's,^kde includedir,# kde includedir,' \
		${WRKSRC}/libk9copy/Makefile.in

.include <bsd.port.post.mk>
