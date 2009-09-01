# New ports collection makefile for:	pver
# Date created:		2008-11-07
# Whom:			Wei-Yu Chen <weiyu@alpha3.cs.nthu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pver
PORTVERSION=	0.15
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.csie.nctu.edu.tw/~weiyu/software/ \
		${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	weiyu.csie+pver@gmail.com
COMMENT=	Show packages which are different version from ports using INDEX-*.db

OPTIONS=	SORT "Sort the result by the package names" Off \
		DB185 "Use BerkeleyDB 1.85/1.86" Off

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS+=	PORTSDIR=${PORTSDIR}
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	bin/pver \
		bin/pver_c \
		bin/pver_dbgen \
		bin/wpver \
		%%DATADIR%%/LICENSE.txt
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

.if defined(WITH_SORT)
MAKE_ARGS+=	-DSORT
.endif

.if defined(WITH_DB185)
MAKE_ARGS+=	-DBSD_DB
.else
USE_BDB=	3+
MAKE_ARGS+=	BDB_VER=${BDB_VER} BDB_LIB_DIR=${BDB_LIB_DIR}
.endif

.if defined(INDEX_DB_FILE)
MAKE_ARGS+=	INDEX_DB_FILE=${INDEX_DB_FILE}
.endif

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL} ${WRKSRC}/LICENSE.txt ${DATADIR}

	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|PORTSDIR|${PORTSDIR}|g' \
		-e 's|__FreeBSD__|${OSREL:C/.[0-9]//}|g' ${PKGDIR}/pkg-message

.include <bsd.port.post.mk>
