# Created by: Alexander Y. Grigoryev <alexander.4mail@gmail.com>
# $FreeBSD$

PORTNAME=	cnagios
PORTVERSION=	0.32
CATEGORIES=	net-mgmt

MAINTAINER=	alexander.4mail@gmail.com
COMMENT=	Curses-based interface for nagios

LICENSE=	ISCL

RUN_DEPENDS=	nagios>=3.0:net-mgmt/nagios

USE_GITHUB=	yes
GH_ACCOUNT=	dannywarren

NAGIOSDIR?=	/var/spool/nagios
ETCDIR=		${PREFIX}/etc/nagios
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-etc-dir="${ETCDIR}" \
		--with-var-dir="${NAGIOSDIR}" \
		--with-status-file="${NAGIOSDIR}/status.dat" \
		--with-nagios-data=3
USES=		ncurses perl5
MAKE_ARGS=	LIBS="-lncurses"
ALL_TARGET=	cnagios

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cnagios

.include <bsd.port.mk>
