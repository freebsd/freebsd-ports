# New ports collection makefile for:	mk-livestatus
# Date created:		10 april 2010
# Whom:			Peter C. Lai <cowbert@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mk-livestatus
PORTVERSION=	1.1.8
CATEGORIES=	net-mgmt
MASTER_SITES=	http://mathias-kettner.de/download/

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Nagios event broker module

LICENSE=	GPLv2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/mk-livestatus/unixcat lib/mk-livestatus/livestatus.o
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

post-patch:
.for i in ${EXAMPLE_FILES}
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin/python|${LOCALBASE}/bin/python|g' \
		-e 's|/var/lib/nagios/rw/live|${COMMAND_FILE}|g' \
		-e 's|/var/run/nagios/rw/live|${COMMAND_FILE}|g' ${WRKSRC}/$i
.endfor
	@${REINPLACE_CMD} -i '' -e 's|/usr/local/nagios/var/rw/live|${COMMAND_FILE}|' \
		${WRKSRC}/src/livestatus.h

post-install:
.if !defined(NOPORTEXAMPLES)
# do not install the outdated perl api!
	${MKDIR} ${EXAMPLESDIR}/api/python
. for i in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/$i  ${EXAMPLESDIR}/$i
. endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
