# New ports collection makefile for:	progsreiserfs
# Date created:				May 13 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	progsreiserfs
PORTVERSION=	0.3.1.r8
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cgsecurity.org/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities and library to manipulate ReiserFS partitions

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_INC_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib -lgnugetopt"
CONFIGURE_ARGS=	--disable-debug

MAN8=		cpfs.reiserfs.8 mkfs.reiserfs.8 reiserfs.8 \
		resizefs.reiserfs.8 tunefs.reiserfs.8

post-patch:
	${REINPLACE_CMD} -e 's|sys/int_types.h|inttypes.h|' ${WRKSRC}/libreiserfs/tools.c
	${REINPLACE_CMD} -e 's|sys/int_types.h|inttypes.h|' ${WRKSRC}/include/reiserfs/*

.include <bsd.port.mk>
