# Created by: Alexander Y. Grigoryev <alexander.4mail@gmail.com>
# $FreeBSD$

PORTNAME=	cnagios
PORTVERSION=	0.31
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://noc.hep.wisc.edu/src/cnagios/ \
		ftp://noc.hep.wisc.edu/src/cnagios/old-versions/

MAINTAINER=	alexander.4mail@gmail.com
COMMENT=	Curses-based interface for nagios

LICENSE=	ISCL

RUN_DEPENDS=	nagios>=3.0:${PORTSDIR}/net-mgmt/nagios

NAGIOSDIR?=	/var/spool/nagios
ETCDIR=		${PREFIX}/etc/nagios
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-etc-dir="${ETCDIR}" \
		--with-var-dir="${NAGIOSDIR}" \
		--with-status-file="${NAGIOSDIR}/status.dat" \
		--with-nagios-data=3
USES=		perl5
ALL_TARGET=	cnagios

post-patch:
# check in next relase if version match, and adjust/remove the next line
	${REINPLACE_CMD} -e 's/0.30/${PORTVERSION}/' ${WRKSRC}/version.h

.include <bsd.port.mk>
