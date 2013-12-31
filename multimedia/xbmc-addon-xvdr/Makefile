# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xbmc-addon-xvdr
PORTVERSION=	0.9.5
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/nox
DISTNAME=	pipelka-${PORTNAME}-xvdr-${PORTVERSION}-0-g${GITHASH}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	XBMC xvdr pvr addon

DEPRECATED=	Depends on expired multimedia/xbmc-pvr
EXPIRATION_DATE=2014-02-01

BUILD_DEPENDS+=	xbmc:${PORTSDIR}/multimedia/xbmc-pvr
RUN_DEPENDS+=	xbmc:${PORTSDIR}/multimedia/xbmc-pvr

GITHASH=	9d3d6ea
WRKSRC=		${WRKDIR}/pipelka-${PORTNAME}-${GITHASH}
PATCH_STRIP=	-p1
USE_AUTOTOOLS=	libtoolize aclocal libtool automake autoconf
ACLOCAL_ARGS=	-I.
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/xbmc
CONFLICTS=	xbmc-[0-9]*

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

post-patch:
	(cd ${WRKSRC} && ${TOUCH} ./NEWS ./AUTHORS ./ChangeLog)

.include <bsd.port.post.mk>
