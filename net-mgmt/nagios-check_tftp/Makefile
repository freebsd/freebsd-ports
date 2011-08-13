# New ports collection makefile for:   check_tftp
# Date created:        7 August 2011
# Whom:                hr <holgerrepp@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	check_tftp
PORTVERSION=	1.0.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://mathias-kettner.de/download/
PKGNAMEPREFIX=	nagios-
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=

MAINTAINER=	holgerrepp@googlemail.com
COMMENT=	Nagios plugin to check tftp servers

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/tftp:${PORTSDIR}/ftp/tftp-hpa

PLIST_DIRSTRY=	libexec/nagios
PLIST_FILES=	libexec/nagios/check_tftp
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-patch:
		${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/check_tftp

do-extract:
		@${MKDIR} ${WRKDIR}
		@${CP} ${DISTDIR}/${PORTNAME}	${WRKDIR}/
do-install:
		@${MKDIR} ${PREFIX}/libexec/nagios
		@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/libexec/nagios

.include <bsd.port.mk>
