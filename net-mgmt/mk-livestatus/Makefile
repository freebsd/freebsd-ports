# Created by: Peter C. Lai <cowbert@gmail.com>
# $FreeBSD$

PORTNAME=	mk-livestatus
PORTVERSION=	1.2.8p22
CATEGORIES=	net-mgmt
MASTER_SITES=	http://mathias-kettner.de/download/
DIST_SUBDIR=	check_mk

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios event broker module

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake

GNU_CONFIGURE=	yes

PLIST_FILES=	lib/mk-livestatus/unixcat \
		lib/mk-livestatus/livestatus.o
SUB_FILES=	pkg-message

PORTEXAMPLES=	*.py README
EXAMPLE_FILES=	example_multisite.py example.py \
		livestatus.py make_nagvis_map.py \
		README

# parameter "command_file" from nagios.cfg
COMMAND_FILE?=	/var/spool/nagios/rw/live

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SINGLE=	NAGIOS
OPTIONS_SINGLE_NAGIOS=	NAGIOS3 NAGIOS4
OPTIONS_DEFAULT=	NAGIOS3

EXAMPLES_USES=	python

NAGIOS3_DESC=	build for nagios-3.x
NAGIOS4_DESC=	build for nagios-4.x

NAGIOS4_CONFIGURE_ON=	--with-nagios4

# perl api is really outdated, do not install!
# Actual version can be found on CPAN
# https://metacpan.org/release/Monitoring-Livestatus
post-extract:
	@${RM} -r ${WRKSRC}/api/perl

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/nagios/var/rw/live|${COMMAND_FILE}|' \
		${WRKSRC}/src/livestatus.h

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		-e 's|/var/lib/nagios/rw/live|${COMMAND_FILE}|g' \
		-e 's|/var/run/nagios/rw/live|${COMMAND_FILE}|g' \
		${PORTEXAMPLES:S|^|${WRKSRC}/api/python/|}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/api/python/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
