# Created by: Oddbjorn Steffensen <oddbjorn@tricknology.org>
# $FreeBSD$

PORTNAME=	web2ldap
PORTVERSION=	1.2.94
CATEGORIES=	www
MASTER_SITES=	http://www.web2ldap.de/download/ \
		http://www.sfr-fresh.com/unix/www/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Python-based WWW gateway to LDAP servers

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap>=2.4.0:net/py-ldap@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/pyweblib/__init__.py:www/py-pyweblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipaddr>0:devel/py-ipaddr@${PY_FLAVOR} \
		${LOCALBASE}/etc/mime.types:misc/mime-support

OPTIONS_DEFINE=	DOCS
USES=		cpe python:2 shebangfix
python_OLD_CMD=	/usr/bin/python2.7
SHEBANG_FILES=	sbin/*.py fcgi/*.py
SUB_FILES=	pkg-message
NO_ARCH=	yes

PORTDOCS=	*
PORTDATA=	*
PLIST_DIRS=	%%DATADIR%%/var/log %%DATADIR%%/var/run

post-patch:
	@${REINPLACE_CMD} -e 's|/opt/fcgi/bin/cgi-fcgi|${LOCALBASE}/bin/cgi-fcgi|g' \
		${WRKSRC}/cgi-bin/web2ldap.cgi
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}/etc|g' \
			  -e 's|nobody|web2ldap|g' \
		${WRKSRC}/etc/web2ldap/web2ldapcnf/standalone.py
	@${FIND} ${WRKSRC} -name '*.orig' -delete -o -name '*.bak' -delete

do-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}
	${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${ECHO_MSG} "==> Installing program files..."
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}; \
		${FIND} * -type d | ${GREP} -vE "^htdocs" | ${CPIO} -p ${STAGEDIR}${DATADIR}; \
		${FIND} * -type f | ${GREP} -vE "^htdocs" | ${CPIO} -pd ${STAGEDIR}${DATADIR})

post-install-DOCS-on:
	@${ECHO_MSG} "==> Installing document files..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}; \
		${FIND} * -type d | ${GREP} "^htdocs" | ${CPIO} -p ${STAGEDIR}${DOCSDIR}; \
		${FIND} * -type f | ${GREP} "^htdocs" | ${CPIO} -pd ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
