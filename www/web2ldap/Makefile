# Created by: Oddbjorn Steffensen <oddbjorn@tricknology.org>
# $FreeBSD$

PORTNAME=	web2ldap
PORTVERSION=	1.1.47
CATEGORIES=	www
MASTER_SITES=	http://www.web2ldap.de/download/ \
		http://www.sfr-fresh.com/unix/www/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Python-based WWW gateway to LDAP servers

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap2>=2.4.0:${PORTSDIR}/net/py-ldap2 \
		${PYTHON_SITELIBDIR}/pyweblib/__init__.py:${PORTSDIR}/www/pyweblib \
		${PYTHON_SITELIBDIR}/ipaddr.py:${PORTSDIR}/devel/py-ipaddr \
		${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

OPTIONS_DEFINE=	DOCS
USE_PYTHON=	yes
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/etc/web2ldap/web2ldapcnf/standalone.py
	@${FIND} ${WRKSRC} -name '*.orig' -delete -o -name '*.bak' -delete

do-build:
	@(cd ${WRKSRC} && ${PYTHON_CMD} ./sbin/compile.py)

do-install:
	@${ECHO_MSG} "==> Installing program files..."
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}; \
		${FIND} * -type d | ${GREP} -vE "^htdocs" | ${CPIO} -p ${STAGEDIR}${DATADIR}; \
		${FIND} * -type f | ${GREP} -vE "^htdocs" | ${CPIO} -pd ${STAGEDIR}${DATADIR})

post-install:
	@${ECHO_MSG} "==> Installing document files..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}; \
		${FIND} * -type d | ${GREP} "^htdocs" | ${CPIO} -p ${STAGEDIR}${DOCSDIR}; \
		${FIND} * -type f | ${GREP} "^htdocs" | ${CPIO} -pd ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
