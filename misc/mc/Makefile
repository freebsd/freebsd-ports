# New ports collection makefile for:	mc
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mc
PORTVERSION=	4.5.51
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/mc

MAINTAINER=	reg@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
.if defined(WITH_NCURSES_PORT)
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.elif defined(WITH_SLANG)
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
.endif

USE_GMAKE=	yes
USE_GLIB=	yes
GNU_CONFIGURE=	yes
.if defined(WITH_SLANG)
CONFIGURE_ARGS=	--with-slang --without-gnome --with-edit
.else
CONFIGURE_ARGS=	--with-ncurses --without-gnome --without-edit
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		midc.1
MAN8=		mcserv.8

.if defined(WITH_SLANG)
PLIST=		${WRKDIR}/PLIST
pre-install:
	@${CAT} ${PKGDIR}/pkg-plist > ${PLIST}
	@${ECHO} bin/mcedit >> ${PLIST}
.endif

.include <bsd.port.mk>
