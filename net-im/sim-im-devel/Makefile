# New Ports Collection Makefile for:	sim-im-devel
# Date created:				18 Apr 2006
# Whom:					Alexey V. Panfilov <sim-im@lehis.ru>
#
# $FreeBSD$

PORTNAME=	sim-im-devel
PORTVERSION=	0.9.5.2236
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	http://sim-im.lehis.ru/dist/ \
		http://www.sim-im.lehis.ru/dist/

MAINTAINER=	ports@subnets.ru
COMMENT=	Plugin-based instant messenger

LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

CONFLICTS=	simicq-[0-9]* sim-im-[0-9]*

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_QT_VER=	3
USE_XORG=	x11 xext xscrnsaver
USE_OPENSSL=	yes
USE_PERL5_BUILD=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

OPTIONS=	KDE "Enable KDE support" off \
		DEBUG "Enable debug" on

.include <bsd.port.pre.mk>

post-patch:
.if !defined(WITH_KDE)
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
	${CONFIGURE_WRKSRC}/configure
.endif

.if !defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=--enable-debug
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
.include "${PORTSDIR}/Mk/bsd.kde.mk"
.endif

.include <bsd.port.post.mk>
