PORTREVISION=	0
PKGNAMESUFFIX=	-icinga2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Icinga2 performance data collector and grapher

MASTERDIR=	${.CURDIR}/../pnp

PLIST=		${.CURDIR}/pkg-plist

RUN_DEPENDS=	${LOCALBASE}/bin/rrdtool:databases/rrdtool \
		${LOCALBASE}/www/icingaweb2/public/index.php:net-mgmt/icingaweb2

MAKE_ARGS=	INSTALL_OPTS= MIX_OPTS= NOSAMPLES=1

NAGIOSDIR?=	/var/spool/icinga2
NAGIOSHTMURL?=	/icingaweb2
NAGIOSUSER?=	icinga
NAGIOSGROUP?=	icinga

.include "${MASTERDIR}/Makefile"
