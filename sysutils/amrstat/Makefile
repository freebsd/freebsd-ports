PORTNAME=	amrstat
PORTVERSION=	20070216
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/jkim

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Utility for LSI Logic's MegaRAID RAID controllers

LICENSE=	BSD2CLAUSE

PLIST_FILES=	etc/periodic/daily/407.status-amr-raid \
		sbin/amrstat

OPTIONS_DEFINE=	MEGARC
MEGARC_DESC=	Install LSI megarc binary port

# We may want this for periodic script and to actually be able
# to fix something in case amrstat reports degraded RAID.
MEGARC_RUN_DEPENDS=	megarc:sysutils/megarc

ALL_TARGET=	${PORTNAME}

PERIODICSCRIPT=	407.status-amr-raid

NO_WRKSUBDIR=	yes

SUB_FILES+=	${PERIODICSCRIPT}

post-extract:
	${RM} ${WRKSRC}/amrstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amrstat ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} \
	    ${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.mk>
