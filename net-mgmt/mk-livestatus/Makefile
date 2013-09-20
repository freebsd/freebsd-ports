# Created by: Peter C. Lai <cowbert@gmail.com>
# $FreeBSD$

PORTNAME=	mk-livestatus
PORTVERSION=	1.2.2p2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://mathias-kettner.de/download/ \
		LOCAL/ohauer
DIST_SUBDIR=	check_mk

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Nagios event broker module

LICENSE=	GPLv2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/mk-livestatus/unixcat \
		lib/mk-livestatus/livecheck \
		lib/mk-livestatus/livestatus.o
PLIST_DIRS=	lib/${PORTNAME}
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
NO_STAGE=	yes
post-extract:
	@${RM} -rf ${WRKSRC}/api/perl

post-patch:
.for i in ${EXAMPLE_FILES}
	@${SED} -i '' -e 's|/usr/bin/python|${LOCALBASE}/bin/python|g' \
		-e 's|/var/lib/nagios/rw/live|${COMMAND_FILE}|g' \
		-e 's|/var/run/nagios/rw/live|${COMMAND_FILE}|g' ${WRKSRC}/$i
.endfor
	@${SED} -i '' -e 's|/usr/local/nagios/var/rw/live|${COMMAND_FILE}|' \
		${WRKSRC}/src/livestatus.h

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	( cd ${WRKSRC} && ${COPYTREE_SHARE} api\* ${EXAMPLESDIR}/ )
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
