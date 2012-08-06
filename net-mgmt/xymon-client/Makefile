# New ports collection makefile for:    xymon-client
# Date created:         24 Jan 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	xymon
PORTVERSION=	4.3.10
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF/xymon/Xymon/${PORTVERSION}
PKGNAMESUFFIX=	-client${PKGNAMESUFFIX2}
DIST_SUBDIR=	repacked

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	System for monitoring servers and networks - Client

LICENSE=	GPLv2

# Options
XYMONUSER?=	xymon
XYMONHOSTIP?=	127.0.0.1

USE_GMAKE=	yes
CONFIGURE_ENV=	MAKE=gmake
MAKE_ENV+=	XYMONUSER="${XYMONUSER}"
MAKE_ENV+=	XYMONHOSTIP="${XYMONHOSTIP}"
USE_RC_SUBR=	xymon-client
PLIST_SUB+=	XYMONUSER="${XYMONUSER}"
CONFIG_FILES=	clientlaunch.cfg xymonclient.cfg localclient.cfg

# Configure script is interactive
do-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

pre-install:
	if ! pw groupshow ${XYMONUSER}; then pw groupadd ${XYMONUSER} -g 280; fi
	if ! pw usershow ${XYMONUSER}; then pw useradd ${XYMONUSER} -g ${XYMONUSER} -u 280 \
		-h - -d ${WWWDIR} -s /usr/sbin/nologin -c "Xymon Monitor"; fi

post-install:
.for i in ${CONFIG_FILES}
	${CP} -np ${WWWDIR}/client/etc/${i}.DIST \
		${WWWDIR}/client/etc/${i}
.endfor

.include <bsd.port.mk>
