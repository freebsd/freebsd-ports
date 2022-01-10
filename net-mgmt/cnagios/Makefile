# Created by: Alexander Y. Grigoryev <alexander.4mail@gmail.com>

PORTNAME=	cnagios
PORTVERSION=	0.33
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	danny@dannywarren.com
COMMENT=	Curses-based interface for nagios

LICENSE=	ISCL

FLAVORS=	nagios3 nagios4

USES=		ncurses perl5

nagios3_PKGNAMESUFFIX=	-nagios3
nagios4_PKGNAMESUFFIX=	-nagios4

nagios3_RUN_DEPENDS=	nagios>=3.0:net-mgmt/nagios
nagios4_RUN_DEPENDS=	nagios4>=4.0:net-mgmt/nagios4

USE_GITHUB=	yes
GH_ACCOUNT=	dannywarren

CONFLICTS_INSTALL=	cnagios-nagios* # bin/cnagios

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
