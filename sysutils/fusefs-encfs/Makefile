# New ports collection makefile for:	fusefs-encfs
# Date created:		2007-01-05
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	encfs
PORTVERSION=	1.3.2
CATEGORIES=	sysutils
MASTER_SITES=	http://arg0.net/users/vgough/download/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	encfs-${PORTVERSION}-1
EXTRACT_SUFX=	.tgz

MAINTAINER=	trasz@freebsd.org
COMMENT=	An encrypted pass-through FUSE filesystem

LIB_DEPENDS=	rlog:${PORTSDIR}/devel/rlog
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod
BUILD_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs

WRKSRC=		${WRKDIR}/encfs-${PORTVERSION}

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS=-L${LOCALBASE}/lib
CFLAGS+=	-pthread
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes

MAN1=		encfs.1 encfsctl.1

.include <bsd.port.mk>
