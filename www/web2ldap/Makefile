# New ports collection makefile for:   web2ldap
# Date created:        21 July 2000
# Whom:                Oddbjorn Steffensen <oddbjorn@tricknology.org>
#
# $FreeBSD$
#

PORTNAME=	web2ldap
PORTVERSION=	1.1.23
CATEGORIES=	www
MASTER_SITES=	http://www.web2ldap.de/download/ \
		http://www.sfr-fresh.com/unix/www/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Python-based WWW gateway to LDAP servers

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap2>=2.4.0:${PORTSDIR}/net/py-ldap2 \
		${PYTHON_SITELIBDIR}/pyweblib/__init__.py:${PORTSDIR}/www/pyweblib \
		${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

USE_PYTHON=	yes

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/etc/web2ldap/web2ldapcnf/standalone.py
	@${FIND} ${WRKSRC} -name '*.orig'  -o -name '*.bak' | ${XARGS} ${RM}

do-build:
	@(cd ${WRKSRC} && ${PYTHON_CMD} ./sbin/compile.py)

do-install:
	@${ECHO_CMD} "==> Installing program files..."
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}; \
		${FIND} * -type d | ${GREP} -vE "^htdocs" | ${CPIO} -p ${DATADIR}; \
		${FIND} * -type f | ${GREP} -vE "^htdocs" | ${CPIO} -pd ${DATADIR})

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} "==> Installing document files..."
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}; \
		${FIND} * -type d | ${GREP} "^htdocs" | ${CPIO} -p ${DOCSDIR}; \
		${FIND} * -type f | ${GREP} "^htdocs" | ${CPIO} -pd ${DOCSDIR})
.endif
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
