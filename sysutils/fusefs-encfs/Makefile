# New ports collection makefile for:	fusefs-encfs
# Date created:		2007-01-05
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	encfs
PORTVERSION=	1.7.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	fusefs-
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	An encrypted pass-through FUSE filesystem

LIB_DEPENDS=	rlog.5:${PORTSDIR}/devel/rlog \
		boost_serialization.4:${PORTSDIR}/devel/boost-libs

WRKSRC=		${WRKDIR}/encfs-${PORTVERSION}

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost-serialization=boost_serialization \
		--with-boost-filesystem=boost_filesystem
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_FUSE=	yes
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
