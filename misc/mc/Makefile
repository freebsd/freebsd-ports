# New ports collection makefile for:	mc
# Date created:		15 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mc
PORTVERSION=	4.6.0
PORTREVISION=	1
CATEGORIES=	misc shells
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers/mc/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Midnight Commander, a free Norton Commander Clone

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-samba --with-configdir=${LOCALBASE}/etc \
		--with-codepagedir=${LOCALBASE}/etc/codepages

.if !defined(WITHOUT_ICONV)
CONFIGURE_ARGS+=--enable-charset
LIB_DEPENDS+=	iconv.3:${PORTSDIR}/converters/libiconv
PLIST_SUB=	CHARSETS=""
.else
PLIST_SUB=	CHARSETS="@comment "
.endif

.if defined(WITHOUT_SLANG)
CONFIGURE_ARGS+=--with-screen=ncurses
.else
CONFIGURE_ARGS+=--with-screen=slang
CONFIGURE_ENV=	CPPFLAGS="-I ${LOCALBASE}/include" \
		LDFLAGS="-ltermcap -L ${LOCALBASE}/lib"
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
.endif

.if defined(WITHOUT_SUBSHELL)
CONFIGURE_ARGS+=--without-subshell
.endif

MAN1=		mc.1 mcedit.1 mcview.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/zip|${LOCALBASE}/bin/zip|' \
		-e 's|/usr/bin/unzip|${LOCALBASE}/bin/unzip|' \
		${WRKSRC}/configure

post-install:
	@${LN} -sf mc ${PREFIX}/bin/midc

.include <bsd.port.mk>
