# New ports collection makefile for:   web2ldap
# Date created:        21 July 2000
# Whom:                Oddbjorn Steffensen <oddbjorn@tricknology.org>
#
# $FreeBSD$
#

PORTNAME=      web2ldap
PORTVERSION=   0.7.9
CATEGORIES=    www
MASTER_SITES=  http://sites.inka.de/ms/python/web2ldap/download/ \
               http://www.tricknolgy.org/ports/

MAINTAINER=    oddbjorn@tricknology.org

RUN_DEPENDS=   ${LOCALBASE}/bin/python:${PORTSDIR}/lang/python \
	       ${LOCALBASE}/lib/python1.5/site-packages/ldapmodule.so:${PORTSDIR}/net/ldapmodule

NO_BUILD=      yes

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/cgi-bin/web2ldap.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/sbin/web2ldap.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/sbin/compile.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/etc/mime.types.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/etc/web2ldap/web2ldapcnf/misc.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/etc/web2ldap/web2ldapcnf/standalone.py.orig
	@${LOCALBASE}/bin/python ${WRKDIR}/${PORTNAME}-${PORTVERSION}/sbin/compile.py
	@${CP} -r ${WRKDIR}/${PORTNAME}-${PORTVERSION}/ ${PREFIX}/${PORTNAME}
	@if [ -w /var/log ]; then ${MKDIR} /var/log/web2ldap; fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
