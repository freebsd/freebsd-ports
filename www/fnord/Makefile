# New ports collection makefile for:	fnord
# Date created:				May 23 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fnord
PORTVERSION=	1.9
CATEGORIES=	www
MASTER_SITES=	http://www.fefe.de/fnord/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Small and fast webserver with CGI-capability

RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools \
		tcpserver:${PORTSDIR}/sysutils/ucspi-tcp

USE_GMAKE=	yes
USE_BZIP2=	yes

PLIST_FILES=	bin/fnord \
		bin/fnord-conf

do-build:
	cd ${WRKSRC}; ${GMAKE} DIET=""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fnord ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/fnord-conf ${PREFIX}/bin/

.include <bsd.port.mk>
