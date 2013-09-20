# Created by: Mike Meyer <mwm@mired.org>
# $FreeBSD$

PORTNAME=	mixer
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	mwm@mired.org
COMMENT=	A startup/shutdown script to preserve mixer settings across reboots

NO_BUILD=	yes
PLIST_FILES=	etc/rc.d/mixer.sh

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/mixer.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
