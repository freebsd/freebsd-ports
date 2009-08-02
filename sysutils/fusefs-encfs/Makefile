# New ports collection makefile for:	fusefs-encfs
# Date created:		2007-01-05
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	encfs
PORTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	fusefs-
EXTRACT_SUFX=	.tgz

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	An encrypted pass-through FUSE filesystem

LIB_DEPENDS=	rlog:${PORTSDIR}/devel/rlog \
		boost_serialization:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod
BUILD_DEPENDS=	${LOCALBASE}/include/fuse.h:${PORTSDIR}/sysutils/fusefs-libs

WRKSRC=		${WRKDIR}/encfs-${PORTVERSION}

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost-serialization=boost_serialization
CONFIGURE_ENV=	LDFLAGS=-L${LOCALBASE}/lib CPPFLAGS=-I${LOCALBASE}/include
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

MAN1=		encfs.1 encfsctl.1

.include <bsd.port.mk>
