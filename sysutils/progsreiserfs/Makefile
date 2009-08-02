# New ports collection makefile for:	progsreiserfs
# Date created:				May 13 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	progsreiserfs
PORTVERSION=	0.3.1.r8
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities and library to manipulate ReiserFS partitions

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-debug --disable-Werror
CFLAGS+=	-Dgetopt_long_only=getopt_long

EXTRA_PATCHES=	${FILESDIR}/extrapatch-progsreiserfs::libmisc::Makefile.in

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.else
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
.endif

MAN8=		cpfs.reiserfs.8 mkfs.reiserfs.8 reiserfs.8 \
		resizefs.reiserfs.8 tunefs.reiserfs.8

post-patch:
	@${REINPLACE_CMD} -e 's|^LIBTOOL=.*|LIBTOOL=${LIBTOOL}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|sys/int_types.h|inttypes.h|' \
		${WRKSRC}/libreiserfs/tools.c ${WRKSRC}/include/reiserfs/*

.include <bsd.port.mk>
