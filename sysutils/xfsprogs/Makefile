# Created by: Craig Rodrigues <rodrigc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfsprogs
PORTVERSION=	3.2.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://oss.sgi.com/projects/xfs/cmd_tars/ \
		ftp://oss.sgi.com/projects/xfs/previous/cmd_tars/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for managing XFS filesystems

LICENSE=	LGPL21 GPLv2
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/doc/COPYING

CPE_PRODUCT=	${PORTNAME}
CPE_VENDOR=	sgi
USES=		cpe gettext gmake libtool:build readline
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPTIMIZER=" "
CONFIGURE_ARGS=	--disable-shared --enable-readline
ALL_TARGET=	# empty

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/utmp/d' \
		${WRKSRC}/quota/report.c ${WRKSRC}/quota/util.c
	@${REINPLACE_CMD} \
		-e 's|/usr/local|${LOCALBASE}|g' \
		-e 's/lio_listio/timer_create/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/#!/s|bash|sh|' \
		${WRKSRC}/include/install-sh ${WRKSRC}/install-sh

post-install:
.for f in mkfs.xfs xfs_copy xfs_db xfs_estimate xfs_fsr xfs_growfs xfs_io \
     xfs_logprint xfs_mdrestore xfs_quota xfs_repair xfs_rtcp
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${f}
.endfor

.include <bsd.port.mk>
