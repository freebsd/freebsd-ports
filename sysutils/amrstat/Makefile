# Created by: Bjoern A. Zeeb <bzeeb+freebsd+ports@zabbadoz.net>
# $FreeBSD$

PORTNAME=	amrstat
PORTVERSION=	20070216
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/jkim

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Utility for LSI Logic's MegaRAID RAID controllers

LICENSE=	BSD2CLAUSE

PLIST_FILES=	etc/periodic/daily/407.status-amr-raid \
		sbin/amrstat

OPTIONS_DEFINE=	MEGARC
MEGARC_DESC=	Install LSI megarc binary port

.include <bsd.port.options.mk>

# We may want this for periodic script and to actually be able
# to fix something in case amrstat reports degraded RAID.
.if ${PORT_OPTIONS:MMEGARC}
RUN_DEPENDS+=	${LOCALBASE}/sbin/megarc:sysutils/megarc
.endif

ALL_TARGET=	${PORTNAME}

LOCALSRCDIR=	${.CURDIR}/files
PERIODICSCRIPT=	407.status-amr-raid

NO_WRKSUBDIR=	yes

SUB_FILES+=	${PERIODICSCRIPT}

post-extract:
	${RM} -f ${WRKSRC}/amrstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amrstat ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/${PERIODICSCRIPT} \
	    ${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.mk>
