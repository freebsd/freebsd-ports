# New ports collection makefile for:   web2ldap
# Date created:        21 July 2000
# Whom:                Oddbjorn Steffensen <oddbjorn@tricknology.org>
#
# $FreeBSD$
#

PORTNAME=	web2ldap
PORTVERSION=	0.15.12
CATEGORIES=	www
MASTER_SITES=	http://www.web2ldap.de/download/ \
		http://www.tricknology.org/ports/

MAINTAINER=	bsam@ipt.ru
COMMENT=	Python-based WWW gateway to LDAP servers

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_ldap.so:${PORTSDIR}/net/py-ldap2 \
		${PYTHON_SITELIBDIR}/pyweblib/__init__.py:${PORTSDIR}/www/pyweblib \
		${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

USE_PYTHON=	yes
USE_REINPLACE=	yes

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/etc/web2ldap/web2ldapcnf/standalone.py

do-build:
	@(cd ${WRKSRC} && ${PYTHON_CMD} ./sbin/compile.py)

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${RM} -f ${WRKSRC}/fcgi/web2ldap.py.orig
	@${RM} -f ${WRKSRC}/scgi/web2ldap.py.orig
	@${RM} -f ${WRKSRC}/etc/web2ldap/web2ldapcnf/standalone.py.orig
	@${RM} -f ${WRKSRC}/etc/web2ldap/web2ldapcnf/standalone.py.bak
	@${RM} -f ${WRKSRC}/sbin/compile.py.orig
	@${RM} -f ${WRKSRC}/sbin/web2ldap.py.orig
	@${CP} -r ${WRKSRC}/ ${PREFIX}/${PORTNAME}
	@if [ -w /var/log ]; then ${MKDIR} /var/log/web2ldap; fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
