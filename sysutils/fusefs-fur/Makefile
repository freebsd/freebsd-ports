# New ports collection makefile for:	fusefs-fur
# Date created:				10 March 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	fur
PORTVERSION=	0.4.6
CATEGORIES=	sysutils palm
MASTER_SITES=	SF/synce/FUR/${PORTVERSION}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	FUR-${PORTVERSION}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	FUSE-based filesystem for Windows CE based devices

LIB_DEPENDS=	rapi.2:${PORTSDIR}/palm/synce-librapi2 \
		fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

OPTIONS=	VCHMOD	"Enable a fake hook for chmod that just returns 0"	on

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GNOME=	pkgconfig
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -DFUSE_USE_VERSION=26
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_VCHMOD)
CONFIGURE_ARGS+=	--enable-void-chmod
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Fur ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
