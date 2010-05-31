# New ports collection makefile for:	xfsprogs
# Date created:				Wed Jun  1 21:48:59 EDT 2005
# Whom:					Craig Rodrigues <rodrigc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfsprogs
PORTVERSION=	2.9.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://oss.sgi.com/projects/xfs/cmd_tars/ \
		ftp://oss.sgi.com/projects/xfs/previous/cmd_tars/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	-1.tar.gz

MAINTAINER=	rodrigc@FreeBSD.ORG
COMMENT=	A set of utilities and library to manipulate an xfs filesystem

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	autoconf:262 libtool:22:env
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
	xfs_io.8 xfs_logprint.8 xfs_mdrestore.8 xfs_metadump.8 xfs_mkfile.8 xfs_ncheck.8 \
	xfs_quota.8 xfs_repair.8 xfs_rtcp.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		Does not compile on less than FreeBSD 7.x
.endif

post-extract:
	${LN} -sf ${WRKDIR}/${PORTNAME}-${PORTVERSION} ${WRKSRC}
	${REINPLACE_CMD} -e '/utmp/d' \
		${WRKSRC}/quota/report.c ${WRKSRC}/quota/util.c

pre-configure:
	${RM} -f ${WRKSRC}/configure

post-configure:
	${FIND} ${WRKSRC} -name "configure" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g'
	${FIND} ${WRKSRC}/include -name "builddefs" | ${XARGS} ${REINPLACE_CMD} -e \
		's|LIBRT =|LIBRT = -lrt|g'

post-patch:
	${FIND} ${WRKDIR} -name "*.m4" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/local|'${LOCALBASE}'|g'
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} -e 's/doc//' -e '/PKG_DOC_DIR/d' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
