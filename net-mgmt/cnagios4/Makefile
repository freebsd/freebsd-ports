# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cnagios
PORTVERSION=	0.32
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	4

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Curses-based interface for nagios

LICENSE=	ISCL

RUN_DEPENDS=	nagios4>=3.0:net-mgmt/nagios4

USES=		ncurses perl5

CONFLICTS_INSTALL=	cnagios

USE_GITHUB=	yes
GH_ACCOUNT=	dannywarren

NAGIOSDIR?=	/var/spool/nagios
ETCDIR=		${PREFIX}/etc/nagios
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-etc-dir="${ETCDIR}" \
		--with-var-dir="${NAGIOSDIR}" \
		--with-status-file="${NAGIOSDIR}/status.dat" \
		--with-nagios-data=3
MAKE_ARGS=	LIBS="-lncurses"
ALL_TARGET=	cnagios

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cnagios

.include <bsd.port.mk>
