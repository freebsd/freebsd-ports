# New ports collection makefile for:   web2ldap
# Date created:        21 July 2000
# Whom:                Oddbjorn Steffensen <oddbjorn@tricknology.org>
#
# $FreeBSD$
#

PORTNAME=	web2ldap
PORTVERSION=	0.8.1
CATEGORIES=	www
MASTER_SITES=	http://www.web2ldap.de/download/ \
		http://www.tricknology.org/ports/

MAINTAINER=	oddbjorn@tricknology.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_ldapmodule.so:${PORTSDIR}/net/ldapmodule

NO_BUILD=	yes
USE_PYTHON=	yes
PYTHON_VERSION=	python2.0

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/cgi-bin/web2ldap.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/sbin/web2ldap.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/sbin/compile.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/etc/mime.types.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/etc/web2ldap/web2ldapcnf/misc.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/etc/web2ldap/web2ldapcnf/standalone.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/etc/web2ldap/web2ldapcnf/hosts.py.orig
	@${LOCALBASE}/bin/python ${WRKDIR}/${PORTNAME}-${PORTVERSION}/sbin/compile.py
	@${CP} -r ${WRKDIR}/${PORTNAME}-${PORTVERSION}/ ${PREFIX}/${PORTNAME}
	@if [ -w /var/log ]; then ${MKDIR} /var/log/web2ldap; fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
