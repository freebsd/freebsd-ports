# New ports collection makefile for:	app_notify
# Date created:				23 March 2007
# Whom:					mayo
#
# $FreeBSD$
#

PORTNAME=	app_notify
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://www.mezzo.net/asterisk/ \
		http://static.oyam.ca/freebsd/ports/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mayo@oyam.ca
COMMENT=	Notify application module for the Asterisk PBX

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk
RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

USE_GMAKE=	yes

ASTETCDIR=	${PREFIX}/etc/asterisk

pre-install:
	${MKDIR} ${ASTETCDIR}

post-install:
	@if [ ! -f ${ASTETCDIR}/dialer_extensions.conf ]; then \
		${CP} -p ${ASTETCDIR}/dialer_extensions.conf.sample ${ASTETCDIR}/dialer_extensions.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
