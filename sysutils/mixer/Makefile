# New ports collection makefile for: mixer
# Date created:		17 February 2002
# Whom:			Mike Meyer <mwm@mired.org>
#
# $FreeBSD$
#

PORTNAME=	mixer
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	mwm@mired.org

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/mixer.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
