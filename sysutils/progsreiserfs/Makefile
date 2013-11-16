# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	progsreiserfs
PORTVERSION=	0.3.1.r8
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities and library to manipulate ReiserFS partitions

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-debug --disable-Werror
CFLAGS+=	-Dgetopt_long_only=getopt_long

EXTRA_PATCHES=	${FILESDIR}/extrapatch-progsreiserfs::libmisc::Makefile.in

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-nls
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^LIBTOOL=.*|LIBTOOL=${LIBTOOL}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|sys/int_types.h|inttypes.h|' \
		${WRKSRC}/libreiserfs/tools.c ${WRKSRC}/include/reiserfs/*

.include <bsd.port.mk>
