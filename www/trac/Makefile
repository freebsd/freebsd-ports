# New ports collection makefile for: trac
# Date created:                      17 April 2004
# Whom:                              Kuei-Feng Li <thinker@branda.to>
#
# $FreeBSD$
#

PORTNAME=	trac
PORTVERSION=	0.10.3.1
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/ \
		ftp://ftp.edgewall.com/pub/trac/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	An enhanced wiki and issue tracking system for software projects

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/neo_cgi.so:${PORTSDIR}/www/clearsilver-python
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	SILVERCITY "Use Silvercity for syntax highlighting" On \
		DOCUTILS   "Allow additional text markup" On \
		PGSQL	   "Use PostgreSQL instead of SQLite3" Off \
		SUBVERSION "Support for subversion RCS" On
CONFLICTS=	ja-trac-*

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=		trac-admin.1 tracd.1

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,@dirrm share/man(/.*)?$$,,g \
		;s,${PYTHON_SITELIBDIR:S,^${PYTHONBASE}/,,},%%PYTHON_SITELIBDIR%%,g \
		;s,share/trac,%%DATADIR%%,g \
		;s,share/examples/trac,%%EXAMPLESDIR%%,g \
		;s,@dirrm (%%PYTHON_SITELIBDIR%%|${PYTHON_LIBDIR:S,${PYTHONBASE}/,,})$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/* ${EXAMPLESDIR}
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.pre.mk>

.if defined(WITH_SILVERCITY)
RUN_DEPENDS+=	${PREFIX}/bin/source2html.py:${PORTSDIR}/textproc/silvercity
.endif

.if defined(WITH_DOCUTILS)
RUN_DEPENDS+=	${PREFIX}/bin/rst2html:${PORTSDIR}/textproc/py-docutils
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:${PORTSDIR}/databases/py-psycopg2
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite20
.endif

.if !defined(WITHOUT_SUBVERSION)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/svn/__init__.py:${PORTSDIR}/devel/subversion-python
.endif

.include <bsd.port.post.mk>
