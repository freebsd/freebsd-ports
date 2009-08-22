# New ports collection makefile for:	spambayes
# Date created:				Sat Feb 1 17:23:02 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spambayes
PORTVERSION=	1.0.4
PORTREVISION=	4
CATEGORIES=	mail python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Bayesian anti-spam filter written in Python

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

OPTIONS=	PYTHON26	"Build with Python 2.6 (with unofficial patch)"	off

USE_PYDISTUTILS=	yes
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

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@if [ -f ${WRKSRC}/${file} ]; then \
		${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR} ; \
	fi
.endfor
	@${MKDIR} ${DOCSDIR}/contrib
	@${INSTALL_DATA} ${WRKSRC}/contrib/* ${DOCSDIR}/contrib
	@${MKDIR} ${DOCSDIR}/utilities
	@${INSTALL_DATA} ${WRKSRC}/utilities/* ${DOCSDIR}/utilities
.endif
	@${MKDIR} ${CACHEDIR}
	@${MKDIR} ${DBDIR}

.include <bsd.port.options.mk>

.if defined(WITH_PYTHON26)
USE_PYTHON=		2.6
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-python26
.else
USE_PYTHON=		2.5
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py25-bsddb
.endif

.include <bsd.port.mk>
