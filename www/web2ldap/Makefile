# New ports collection makefile for:   web2ldap
# Date created:        21 July 2000
# Whom:                Oddbjorn Steffensen <oddbjorn@tricknology.org>
#
# $FreeBSD$
#

PORTNAME=	web2ldap
PORTVERSION=	0.15.9
CATEGORIES=	www
MASTER_SITES=	http://www.web2ldap.de/download/ \
		http://www.tricknology.org/ports/

MAINTAINER=	bsam@ipt.ru
COMMENT=	Python-based WWW gateway to LDAP servers

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_ldap.so:${PORTSDIR}/net/py-ldap2

NO_BUILD=	yes
USE_PYTHON=	yes

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/fcgi/web2ldap.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/scgi/web2ldap.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/etc/web2ldap/web2ldapcnf/standalone.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/etc/mime.types.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/sbin/compile.py.orig
	@${RM} -f ${WRKDIR}/${PORTNAME}-${PORTVERSION}/sbin/web2ldap.py.orig
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/python ./sbin/compile.py)
	@${CP} -r ${WRKDIR}/${PORTNAME}-${PORTVERSION}/ ${PREFIX}/${PORTNAME}
	@if [ -w /var/log ]; then ${MKDIR} /var/log/web2ldap; fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
