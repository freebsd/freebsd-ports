# ex:ts=8
# New ports collection makefile for:	slmon
# Date created:			Nov 13, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	slmon
PORTVERSION=	0.5.13
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	S-Lang System Monitor

LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		slang.2:${PORTSDIR}/devel/libslang2

MAKE_JOBS_SAFE=  yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		slmon.1
PLIST_FILES=	bin/slmon

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -lncurses -lm

.include <bsd.port.mk>
