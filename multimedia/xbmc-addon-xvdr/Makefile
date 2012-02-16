# New ports collection makefile for:	xbmc-addon-xvdr
# Date created:			Sat Oct  8 16:27:14 CEST 2011
# Whom:				Juergen Lock <nox@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xbmc-addon-xvdr
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/nox
DISTNAME=	pipelka-${PORTNAME}-xvdr-${PORTVERSION}-0-g${GITHASH}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	XBMC xvdr pvr addon

BUILD_DEPENDS+=	xbmc:${PORTSDIR}/multimedia/xbmc-pvr
RUN_DEPENDS+=	xbmc:${PORTSDIR}/multimedia/xbmc-pvr

GITHASH=	9d3d6ea
WRKSRC=		${WRKDIR}/pipelka-${PORTNAME}-${GITHASH}
PATCH_STRIP=	-p1
USE_AUTOTOOLS=	libtoolize aclocal libtool automake autoconf
MAKE_JOBS_SAFE=	yes
ACLOCAL_ARGS=	-I.
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/xbmc
CONFLICTS=	xbmc-[0-9]*

post-patch:
	(cd ${WRKSRC} && ${TOUCH} ./NEWS ./AUTHORS ./ChangeLog)

.include <bsd.port.mk>
