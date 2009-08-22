# New ports collection makefile for:    xymon-client
# Date created:         24 Jan 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	xymon
PORTVERSION=	4.2.3
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF/hobbitmon/hobbitserver/${PORTVERSION}
PKGNAMESUFFIX=	-client${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	System for monitoring servers and networks - Client

# Options
BBUSER?=	hobbit
BBHOSTIP?=	127.0.0.1

USE_GMAKE=	yes
CONFIGURE_ENV=	MAKE=gmake
MAKE_ENV+=	BBUSER="${BBUSER}"
MAKE_ENV+=	BBHOSTIP="${BBHOSTIP}"
USE_RC_SUBR=	hobbit-client.sh
PLIST_SUB+=	BBUSER="${BBUSER}"
CONFIG_FILES=	clientlaunch.cfg hobbitclient.cfg localclient.cfg

# Configure script is interactive
do-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

pre-install:
	if ! pw groupshow ${BBUSER}; then pw groupadd ${BBUSER} -g 280; fi
	if ! pw usershow ${BBUSER}; then pw useradd ${BBUSER} -g ${BBUSER} -u 280 \
		-h - -d ${WWWDIR} -s /usr/sbin/nologin -c "Hobbit Monitor"; fi

post-install:
.for i in ${CONFIG_FILES}
	${CP} -np ${WWWDIR}/client/etc/${i}-dist \
		${WWWDIR}/client/etc/${i}
.endfor

.include <bsd.port.mk>
