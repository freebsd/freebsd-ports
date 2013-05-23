# Created by: Alexey V. Panfilov <sim-im@lehis.ru>
# $FreeBSD$

PORTNAME=	sim-im-devel
PORTVERSION=	0.9.5.2236
PORTREVISION=	6
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
USE_AUTOTOOLS=	libtool
USE_QT_VER=	3
USE_XORG=	x11 xext xscrnsaver
USE_OPENSSL=	yes
USE_PERL5_BUILD=	yes
USES=		gettext
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	KDE3 DEBUG
OPTIONS_DEFAULT=	DEBUG

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

post-patch:
.if ! ${PORT_OPTIONS:MKDE3}
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
	${CONFIGURE_WRKSRC}/configure
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MKDE3}
USE_KDELIBS_VER=3
PLIST_SUB+=	KDE="" \
		SPELL="@comment "
.include "${PORTSDIR}/Mk/bsd.kde.mk"
.else
CONFIGURE_ARGS+=--disable-kde --enable-mt
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
PLIST_SUB+=	KDE="@comment " \
		SPELL=""
.endif

.include <bsd.port.post.mk>
