# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spambayes
PORTVERSION=	1.1b1
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Bayesian anti-spam filter written in Python

LICENSE=	PSFL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsddb>0:${PORTSDIR}/databases/py-bsddb \
		${PYTHON_PKGNAMEPREFIX}dns>=2.0:${PORTSDIR}/dns/py-dns \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0.2:${PORTSDIR}/devel/py-lockfile

USES=		python:2
USE_PYTHON=	distutils autoplist

USE_RC_SUBR=	pyspamd

LOCALSTATDIR?=	/var/db/spambayes
DBDIR?=		${LOCALSTATDIR}/dbs
CACHEDIR?=	${LOCALSTATDIR}/cache

PLIST_SUB+=	LOCALSTATDIR=${LOCALSTATDIR} \
		DBDIR=${DBDIR} \
		CACHEDIR=${CACHEDIR}

SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

PORTDOCS=	CHANGELOG.txt \
		LICENSE.txt \
		NEWTRICKS.txt \
		POP3PROXY.txt \
		README-DEVEL.txt \
		README.txt \
		TESTING.txt \
		WHAT_IS_NEW.txt \
		utilities/ \
		contrib/

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CHMOD} -Rf u+w ${WRKSRC}

post-patch:
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 -x \
		${REINPLACE_CMD} -E \
		-e 's|/usr/bin/env python|${PYTHONBASE}/bin/${PYTHON_VERSION}|'
	@${FIND} ${WRKSRC}/utilities ${WRKSRC}/contrib ${WRKSRC}/spambayes\
		-type f -name *.bak | ${XARGS} ${RM}
	@${REINPLACE_CMD} -e \
		'/persistent_storage_file/s|hammie.db|${DBDIR}/hammie.db|' \
		-e \
		'/messageinfo_storage_file/s|spambayes.messageinfo.db|${DBDIR}/spambayes.messageinfo.db|' \
		-e \
		'/spam_cache/s|pop3proxy-spam-cache|${CACHEDIR}/pop3proxy-spam-cache|' \
		-e \
		'/ham_cache/s|pop3proxy-ham-cache|${CACHEDIR}/pop3proxy-ham-cache|' \
		-e \
		'/unknown_cache/s|pop3proxy-unknown-cache|${CACHEDIR}/pop3proxy-unknown-cache|' \
		${WRKSRC}/spambayes/Options.py

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	@if [ -f ${WRKSRC}/${file} ]; then \
		${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR} ; \
	fi
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/contrib
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/utilities
	@${INSTALL_DATA} ${WRKSRC}/contrib/* ${STAGEDIR}${DOCSDIR}/contrib
	@${INSTALL_DATA} ${WRKSRC}/utilities/* ${STAGEDIR}${DOCSDIR}/utilities
.endif
	@${MKDIR} ${STAGEDIR}${CACHEDIR}/pop3proxy-spam-cache
	@${MKDIR} ${STAGEDIR}${CACHEDIR}/pop3proxy-ham-cache
	@${MKDIR} ${STAGEDIR}${CACHEDIR}/pop3proxy-unknown-cache
	@${MKDIR} ${STAGEDIR}${DBDIR}

.include <bsd.port.mk>
