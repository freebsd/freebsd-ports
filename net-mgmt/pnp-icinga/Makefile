# $FreeBSD$

PKGNAMESUFFIX=	-icinga

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Icinga performance data collector and grapher

MASTERDIR=	${.CURDIR}/../pnp

RUN_DEPENDS=	${LOCALBASE}/bin/rrdtool:${PORTSDIR}/databases/rrdtool \
		${LOCALBASE}/www/icinga/main.html:${PORTSDIR}/net-mgmt/icinga-classicweb

NAGIOSDIR?=	/var/spool/icinga
NAGIOSHTMURL?=	/icinga
NAGIOSUSER?=	icinga
NAGIOSGROUP?=	icinga

.include "${MASTERDIR}/Makefile"
