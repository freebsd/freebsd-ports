# New ports collection makefile for:	progsreiserfs
# Date created:				May 13 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	progsreiserfs
PORTVERSION=	0.3.1.r8
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities and library to manipulate ReiserFS partitions

USE_GETOPT_LONG=yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-debug

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.else
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
.endif

MAN8=		cpfs.reiserfs.8 mkfs.reiserfs.8 reiserfs.8 \
		resizefs.reiserfs.8 tunefs.reiserfs.8

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
BROKEN=		"Does not compile on non-i386 and non-amd64"
.endif

.if ${OSVERSION} >= 500041
CFLAGS+=	-Dgetopt_long_only=getopt_long
EXTRA_PATCHES=	${FILESDIR}/extrapatch-progsreiserfs::libmisc::Makefile.in
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^LIBTOOL=.*|LIBTOOL=${LIBTOOL}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|sys/int_types.h|inttypes.h|' \
		${WRKSRC}/libreiserfs/tools.c ${WRKSRC}/include/reiserfs/*

.include <bsd.port.post.mk>
