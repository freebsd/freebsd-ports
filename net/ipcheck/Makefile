# New ports collection makefile for:	ipcheck
# Date created:		24 Mar 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ipcheck
PORTVERSION=	0.198
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	lioux

MAINTAINER=	lioux@FreeBSD.org

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

.ifdef(WITH_SNMP)
RUN_DEPENDS+=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/pysnmp/v2c.py:${PORTSDIR}/net/py-snmp
.endif

pre-everything::
.ifndef(WITH_SNMP)
	@${ECHO_MSG} '===> Enable SNMP support by defining WITH_SNMP'
.endif

do-patch:
	@${REINPLACE_CMD} \
		-e "s!/usr/bin/python!${LOCALBASE}/bin/python!" \
		-e "s!ppp0!tun0!" \
			${WRKDIR}/ipcheck.py

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/ipcheck.py ${PREFIX}/bin/

.include <bsd.port.mk>
