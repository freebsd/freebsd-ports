# New ports collection makefile for:	mc
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME?=	mc
PORTVERSION=	4.5.55
PORTREVISION?=	4
CATEGORIES?=	misc
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/mc/4.5

MAINTAINER=	fjoe@FreeBSD.org

.if !defined(WITHOUT_ISPELL)
BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
.endif
.if !defined(WITHOUT_SLANG)
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
.endif
.if !defined(WITHOUT_ICONV)
LIB_DEPENDS+=	iconv.3:${PORTSDIR}/converters/libiconv
.endif
.if ${PORTNAME} == "mc"
LIB_DEPENDS+=	intl.4:${PORTSDIR}/devel/gettext
.endif

USE_GMAKE=	yes
USE_GNOMENG=	yes
.if ${PORTNAME} == "mc"
USE_GNOME=	glib12
.else
USE_GNOME=	gnomeprefix gnomelibs
.endif
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
.if !defined(WITHOUT_SLANG)
CONFIGURE_ARGS=	--with-slang
.else
CONFIGURE_ARGS=	--with-ncurses
.endif
.if !defined(WITHOUT_ICONV)
CONFIGURE_ARGS+=--enable-charset --with-libiconv-prefix=${LOCALBASE}
PLIST_SUB=	CHARSETS=""
.else
PLIST_SUB=	CHARSETS="@comment "
.endif
.if ${PORTNAME} == "mc"
CONFIGURE_ARGS+=--without-gnome
.else
CONFIGURE_ARGS+=--without-edit
.endif
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS="-L${LOCALBASE}/lib -lintl" \
		LOCALBASE=${LOCALBASE}
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
.if ${PORTNAME} == "mc"
PLIST_SUB+=	GNOMEMC="@comment " MC="" SHARE_PATH="share"
MAN1=		mc.1 mcedit.1
.else
PLIST_SUB+=	GNOMEMC="" MC="@comment " SHARE_PATH="share/gnome"
.endif

post-patch:
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${REINPLACE_CMD} \
		-e 's|\$$(libdir)/mc|\$$(datadir)/mc|g' \
		-e 's|\$$(datadir)/locale|\$$(prefix)/share/locale|g'
.if ${PORTNAME} != "mc"
	@${REINPLACE_CMD} -e 's|^SUBDIRS = intl po vfs edit src lib doc|SUBDIRS = intl po vfs lib|' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|DRAR=/usr/bin|DRAR=${LOCALBASE}/bin|' \
		${WRKSRC}/vfs/extfs/urar.in
	@${REINPLACE_CMD} -e 's|/usr/bin/\(.*\)zip|${LOCALBASE}/bin/\1zip|' \
		${WRKSRC}/vfs/extfs/uzip

.if ${PORTNAME} == "mc"
post-install:
	@${LN} -sf mc ${PREFIX}/bin/midc
.endif

.include <bsd.port.mk>
