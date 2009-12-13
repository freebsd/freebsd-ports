# New ports collection makefile for:	quixote-session2
# Date created:		15 June 2005
# Whom:	      		Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	session2
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://quixote.idyll.org/session2/ \
		http://dryice.name/computer/FreeBSD/distfiles/
DISTNAME=	session2-${PORTVERSION}

MAINTAINER=	dryice@dryice.name
COMMENT=	A quixote session manager with persistence support

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	0.6

OPTIONS=	MYSQL "MySQLdb support" on
OPTIONS+=	POSTGRESQL "psycopg support" on

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb
.endif

.if defined(WITH_POSTGRESQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopgmodule.so:${PORTSDIR}/databases/py-psycopg
.endif

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ChangeLog default.css README.html README.txt TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
