# New ports collection makefile for:	jailaudit
# Date created:				21 October 2005
# Whom:					cryx
#
# $FreeBSD$
#

PORTNAME=	jailaudit
PORTVERSION=	1.2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://outpost.h3q.com/software/jailaudit/

MAINTAINER=	cryx-ports@h3q.com
COMMENT=	Script to generate portaudit reports for jails

RUN_DEPENDS=	${LOCALBASE}/sbin/portaudit:${PORTSDIR}/ports-mgmt/portaudit

USE_BZIP2=	yes

PERIODICDIR?=	${PREFIX}/etc/periodic
REPORTDIR?=	${PREFIX}/jailaudit/reports
TMPDIR?=	${PREFIX}/jailaudit/tmp

PLIST_SUB+=	PERIODICDIR="${PERIODICDIR:S,^${PREFIX}/,,}" \
		REPORTDIR="${REPORTDIR:S,^${PREFIX}/,,}" \
		TMPDIR="${TMPDIR:S,^${PREFIX}/,,}"

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 501000 )
IGNORE=		needs the jls utility which was added in FreeBSD 5.1
.endif

.include <bsd.port.post.mk>
