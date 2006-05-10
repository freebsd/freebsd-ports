# New ports collection makefile for:	spambayes
# Date created:				Sat Feb 1 17:23:02 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spambayes
PORTVERSION=	1.0.4
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/(.)\.(..)\.(.)$/\1\2\3/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Bayesian anti-spam filter written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

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

.include <bsd.port.mk>
