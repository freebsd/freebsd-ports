# New ports collection makefile for:	xfsprogs
# Date created:				Wed Jun  1 21:48:59 EDT 2005
# Whom:					Craig Rodrigues <rodrigc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfsprogs
PORTVERSION=	2.6.25
CATEGORIES=	sysutils
MASTER_SITES=	ftp://oss.sgi.com/projects/xfs/cmd_tars/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	rodrigc@FreeBSD.ORG
COMMENT=	A set of utilities and library to manipulate an xfs filesystem

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	yes
USE_AUTOCONF_VER=	259
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=		INSTALL="${INSTALL} ${_BINOWNGRP}" \
			CFLAGS="${CFLAGS}" \
			LIBTOOL=${LIBTOOL}
MAKE_ENV+=		INSTALL="${INSTALL} ${_BINOWNGRP}"
CONFIGURE_ARGS+=	--disable-shared --enable-readline
ALL_TARGET=

MAN5=	xfs.5
MAN8=	fsck.xfs.8 mkfs.xfs.8 xfs_admin.8 xfs_bmap.8 xfs_check.8 \
	xfs_copy.8 xfs_db.8 xfs_freeze.8 xfs_growfs.8 xfs_info.8 \
	xfs_io.8 xfs_logprint.8 xfs_mkfile.8 xfs_ncheck.8 \
	xfs_repair.8 xfs_rtcp.8

pre-configure:
	${RM} -f ${WRKSRC}/configure

post-configure:
	${FIND} ${WRKSRC} -name "configure" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g'

.include <bsd.port.mk>
