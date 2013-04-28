# Created by: Rashid N. Achilov <shelton@granch.ru>
# $FreeBSD$

PORTNAME=		kkbswitch
PORTVERSION=		1.4.3
PORTREVISION=	9
CATEGORIES=		sysutils kde
MASTER_SITES=		SF

MAINTAINER=		citycat4@ngs.ru
COMMENT=		Keyboard layout switcher and indicator for KDE 3.x

EXTRA_PATCHES=		${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool

CONFIGURE_ARGS += 	--with-qt-dir=${QT_PREFIX} \
			--with-extra-includes=${LOCALBASE}/include \
			--with-extra-libs=${LOCALBASE}/lib

DOCSDIR=		share/doc/HTML/en/${PORTNAME}

MAN1=			kkbswitch.1

OPTIONS_DEFINE=	RU_UA_LAYOUT
RU_UA_LAYOUT_DESC=	With additional RU_UA keyboard layout

PLIST_SUB=		PREFIX=${PREFIX} \
			LOCALBASE=${LOCALBASE} \
			DOCSDIR=${DOCSDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRU_UA_LAYOUT}
CONFIGURE_ARGS+=	--enable-ru-ua-layout
PLIST_SUB+=		LAYOUT=""
.else
PLIST_SUB+=		LAYOUT="@comment "
.endif

.include <bsd.port.mk>
