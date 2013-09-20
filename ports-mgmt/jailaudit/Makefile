# Created by: Philipp Wuensche <cryx-ports@h3q.com>
# $FreeBSD$

PORTNAME=	jailaudit
PORTVERSION=	1.4
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://outpost.h3q.com/software/jailaudit/

MAINTAINER=	cryx-ports@h3q.com
COMMENT=	Script to generate portaudit reports for jails

RUN_DEPENDS=	${LOCALBASE}/sbin/portaudit:${PORTSDIR}/ports-mgmt/portaudit

USE_BZIP2=	yes

PERIODICDIR?=	${PREFIX}/etc/periodic
REPORTDIR?=	${PREFIX}/jailaudit/reports
XTMPDIR?=	${PREFIX}/jailaudit/tmp

PLIST_SUB+=	PERIODICDIR="${PERIODICDIR:S,^${PREFIX}/,,}" \
		REPORTDIR="${REPORTDIR:S,^${PREFIX}/,,}" \
		XTMPDIR="${XTMPDIR:S,^${PREFIX}/,,}"

NO_STAGE=	yes
.include <bsd.port.mk>
