# New Ports Collection Makefile for:	sim-im
# Date created:				4 Nov 2002
# Whom:					Josef El-Rayes <j.el-rayes@daemon.li>
#
# $FreeBSD$

PORTNAME=	sim-im
PORTVERSION=	0.9.4.3
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_BERLIOS} \
		http://sim-im.lehis.ru/dist/ \
		http://www.sim-im.lehis.ru/dist/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:S/-im//}-${PORTVERSION}

MAINTAINER=	sim-im@lehis.ru
COMMENT=	Plugin-based instant messenger

LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

CONFLICTS=	simicq-[0-9]* sim-im-devel-[0-9]*

#EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	libtool:15
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_XORG=	x11 xext ice xscrnsaver

.if !defined(WITH_KDE)
CONFIGURE_ARGS+=--disable-kde --enable-mt
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
PLIST_SUB+=	KDE="@comment " \
		SPELL=""
.else
USE_KDELIBS_VER=3
PLIST_SUB+=	KDE="" \
		SPELL="@comment "
.endif

pre-everything::
.if !defined(WITH_KDE)
	@${ECHO_MSG} "You can enable KDE support by defining WITH_KDE."
.endif

post-patch:
.if !defined(WITH_KDE)
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
		${CONFIGURE_WRKSRC}/configure
.endif

.include <bsd.port.mk>
