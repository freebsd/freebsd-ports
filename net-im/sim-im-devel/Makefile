# New Ports Collection Makefile for:	sim-im-devel
# Date created:				18 Apr 2006
# Whom:					Alexey V. Panfilov <sim-im@lehis.ru>
#
# $FreeBSD$

PORTNAME=	sim-im-devel
PORTVERSION=	0.9.5.970
CATEGORIES=	net-im
MASTER_SITES=	http://sim-im.lehis.ru/dist/

MAINTAINER=	sim-im@lehis.ru
COMMENT=	Plugin-based instant messenger

LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

CONFLICTS=	simicq-[0-9]* sim-im-[0-9]*

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_QT_VER=	3
USE_OPENSSL=	yes
USE_PERL5_BUILD=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CONFIGURE_ARGS=	--prefix=${PREFIX} --x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib

OPTIONS=	KDE "Enable KDE support" off \
		DEBUG "Enable debug" on

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options
.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

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

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

.include <bsd.port.mk>
