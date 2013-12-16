# Created by: Wei-Yu Chen <weiyu@alpha3.cs.nthu.edu.tw>
# $FreeBSD$

PORTNAME=	pver
PORTVERSION=	0.16
PORTREVISION=	0
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.csie.nctu.edu.tw/~weiyu/software/ \
		${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Show packages which are different version from ports using INDEX-*.db

OPTIONS_DEFINE=	SORT DB185
SORT_DESC=	Sort the result by the package names
DB185_DESC=	Use BerkeleyDB 1.85/1.86

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS+=	PORTSDIR=${PORTSDIR}
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	bin/pver \
		bin/pver_c \
		bin/pver_dbgen \
		bin/wpver \
		%%DATADIR%%/LICENSE.txt
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSORT}
MAKE_ARGS+=	-DSORT
.endif

.if ${PORT_OPTIONS:MDB185}
MAKE_ARGS+=	-DBSD_DB
.else
USE_BDB=	41+
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
