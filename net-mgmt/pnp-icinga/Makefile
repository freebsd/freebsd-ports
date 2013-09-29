# $FreeBSD$

PKGNAMESUFFIX=	-icinga

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Icinga performance data collector and grapher

MASTERDIR=	${.CURDIR}/../pnp

RUN_DEPENDS=	${LOCALBASE}/bin/rrdtool:${PORTSDIR}/databases/rrdtool \
		icinga:${PORTSDIR}/net-mgmt/icinga

NAGIOSDIR?=	/var/spool/icinga
NAGIOSHTMURL?=	/icinga
NAGIOSUSER?=	icinga
NAGIOSGROUP?=	icinga

.include "${MASTERDIR}/Makefile"
