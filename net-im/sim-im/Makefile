# New Ports Collection Makefile for:	sim-icq
# Date created:				4 Nov 2002
# Whom:					Josef El-Rayes <j.el-rayes@daemon.li>
#
# $FreeBSD$

PORTNAME=	simicq
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/mi/m-i/}
DISTNAME=	${PORTNAME:S/icq//}-${PORTVERSION}-2

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Plugin-based instant messenger

LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt

WRKSRC=		${WRKDIR}/${DISTNAME:S/-2//}
USE_GMAKE=	yes
USE_QT_VER=	3
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
PLIST_SUB+=	SSL=""
.else
CONFIGURE_ARGS+=--disable-openssl
PLIST_SUB+=	SSL="@comment "
.endif

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
.if !defined(WITHOUT_SSL)
	@${ECHO_MSG} "You can disable SSL support by defining WITHOUT_SSL."
.endif
.if !defined(WITHOUT_KDE)
	@${ECHO_MSG} "You can disable KDE support by defining WITHOUT_KDE."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
		${CONFIGURE_WRKSRC}/configure

.include <bsd.port.mk>
