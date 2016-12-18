# Created by: Peter C. Lai <cowbert@gmail.com>
# $FreeBSD$

PORTNAME=	mk-livestatus
PORTVERSION=	1.2.8p15
CATEGORIES=	net-mgmt
MASTER_SITES=	http://mathias-kettner.de/download/ \
		LOCAL/ohauer
DIST_SUBDIR=	check_mk

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios event broker module

LICENSE=	GPLv2

USES=		compiler:c++11-lib gmake
GNU_CONFIGURE=	yes

OPTIONS_SINGLE=	NAGIOS
OPTIONS_SINGLE_NAGIOS=	NAGIOS3 NAGIOS4
OPTIONS_DEFAULT=	NAGIOS3

NAGIOS3_DESC= build for nagios-3.x
NAGIOS4_DESC= build for nagios-4.x

NAGIOS4_CONFIGURE_ON=	--with-nagios4

.include <bsd.port.options.mk>

PLIST_FILES=	lib/mk-livestatus/unixcat \
		lib/mk-livestatus/livestatus.o
SUB_FILES=	pkg-message
SUB_LIST=	PREFIX=${PREFIX}

PORTEXAMPLES=	*
EXAMPLE_FILES=	api/python/example_multisite.py \
		api/python/example.py \
		api/python/livestatus.py \
		api/python/make_nagvis_map.py \
		api/python/README

# parameter "command_file" from nagios.cfg
COMMAND_FILE?=	/var/spool/nagios/rw/live

# perl api is really outdated, do not install!
# Actual version can be found on CPAN
# http://search.cpan.org/~nierlein/Monitoring-Livestatus/
post-extract:
	@${RM} -r ${WRKSRC}/api/perl

post-patch:
	@${SED} -i '' -e 's|/usr/bin/python|${LOCALBASE}/bin/python2.7|g' \
		-e 's|/var/lib/nagios/rw/live|${COMMAND_FILE}|g' \
		-e 's|/var/run/nagios/rw/live|${COMMAND_FILE}|g' \
		${EXAMPLE_FILES:S|^|${WRKSRC}/|}
	@${SED} -i '' -e 's|/usr/local/nagios/var/rw/live|${COMMAND_FILE}|' \
		${WRKSRC}/src/livestatus.h

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	( cd ${WRKSRC} && ${COPYTREE_SHARE} api\* ${STAGEDIR}${EXAMPLESDIR}/ )

.include <bsd.port.mk>
