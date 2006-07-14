# New Ports Collection Makefile for:	sim-im
# Date created:				4 Nov 2002
# Whom:					Josef El-Rayes <j.el-rayes@daemon.li>
#
# $FreeBSD$

PORTNAME=	sim-im
PORTVERSION=	0.9.4
CATEGORIES=	net-im kde
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:S/-im//}-${PORTVERSION}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Plugin-based instant messenger

LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

CONFLICTS=	simicq-[0-9]* sim-im-devel-[0-9]*

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	libtool:15
USE_OPENSSL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITHOUT_KDE)
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
.if !defined(WITHOUT_KDE)
	@${ECHO_MSG} "You can disable KDE support by defining WITHOUT_KDE."
.endif

post-patch:
.if defined(WITHOUT_KDE)
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
		${CONFIGURE_WRKSRC}/configure
.endif

.include <bsd.port.mk>
