# Created by: Craig Rodrigues <rodrigc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfsprogs
PORTVERSION=	2.9.8
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://oss.sgi.com/projects/xfs/cmd_tars/ \
		ftp://oss.sgi.com/projects/xfs/previous/cmd_tars/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	-1.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of utilities and library to manipulate an XFS filesystem

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

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/utmp/d' \
		${WRKSRC}/quota/report.c ${WRKSRC}/quota/util.c
	@${REINPLACE_CMD} \
		-e 's|/usr/local|${LOCALBASE}|g' \
		-e 's/lio_listio/timer_create/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|$$(PKG_DOC_DIR)|$$(DESTDIR)&|g' ${WRKSRC}/Makefile
.for dir in db doc fsck growfs io logprint mdrestore mkfs quota repair rtcp
	@${REINPLACE_CMD} -E 's,PKG_(BIN|DOC|INC|SBIN)_DIR,DESTDIR)$$(&,g' \
		${WRKSRC}/${dir}/Makefile
.endfor
.for i in 3 5 8
	@${REINPLACE_CMD} 's|$$(PKG_MAN_DIR)|$$(DESTDIR)&|g' \
		${WRKSRC}/man/man${i}/Makefile
.endfor
	@${REINPLACE_CMD} 's|$$(PKG_LOCALE_DIR)|$$(DESTDIR)&|' \
		${WRKSRC}/include/buildmacros

post-install:
.for f in xfs_db xfs_growfs xfs_io xfs_logprint xfs_mdrestore xfs_quota xfs_rtcp
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
.for f in xfs_repair mkfs.xfs
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${f}
.endfor

.include <bsd.port.mk>
