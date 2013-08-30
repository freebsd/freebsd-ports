# Created by: Kuei-Feng Li <thinker@branda.to>
# $FreeBSD$

PORTNAME=	trac
PORTVERSION=	1.0.1
CATEGORIES=	www devel python
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/ \
		ftp://ftp.edgewall.com/pub/trac/
DISTNAME=	Trac-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	An enhanced wiki and issue tracking system for software projects

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.6:${PORTSDIR}/textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}Babel>=0.9.5:${PORTSDIR}/devel/py-babel
RUN_DEPENDS:=	${BUILD_DEPENDS}

BROKEN=		fails to configure

OPTIONS_DEFINE=		SILVERCITY DOCUTILS PYGMENTS TZ PGSQL SVN
OPTIONS_DEFAULT=	SILVERCITY DOCUTILS PYGMENTS TZ SVN
SILVERCITY_DESC=	Silvercity for syntax highlighting
DOCUTILS_DESC=		Allow additional text markup
PYGMENTS_DESC=		Use generic syntax highlighter
TZ_DESC=		Process Time Zones

CONFLICTS=	ja-trac-[0-9]*

USE_PYTHON=	2.7-
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Trac
PYDISTUTILS_NOEGGINFO=	yes

USE_RC_SUBR=	tracd
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSILVERCITY}
RUN_DEPENDS+=	${LOCALBASE}/bin/source2html.py:${PORTSDIR}/textproc/silvercity
.endif

.if ${PORT_OPTIONS:MDOCUTILS}
RUN_DEPENDS+=	${LOCALBASE}/bin/rst2html:${PORTSDIR}/textproc/py-docutils
.endif

.if ${PORT_OPTIONS:MPYGMENTS}
RUN_DEPENDS+=	${LOCALBASE}/bin/pygmentize:${PORTSDIR}/textproc/py-pygments
.endif

.if ${PORT_OPTIONS:MTZ}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopg2/__init__.py:${PORTSDIR}/databases/py-psycopg2
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MSVN}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/svn/__init__.py:${PORTSDIR}/devel/py-subversion
.endif

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

pre-install:
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/contrib/cgi-bin/trac.fcgi \
	    ${WRKSRC}/contrib/cgi-bin/trac.cgi

post-install:
	@${MKDIR} ${EXAMPLESDIR}/sample-plugins
	@${MKDIR} ${EXAMPLESDIR}/rpm
	@${INSTALL_DATA} ${WRKSRC}/contrib/rpm/* ${EXAMPLESDIR}/rpm
	@${FIND} ${WRKSRC}/contrib -type f -maxdepth 1 -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/ \;
. for d in permissions workflow
	@${MKDIR} ${EXAMPLESDIR}/sample-plugins/${d}
	@${INSTALL_DATA} ${WRKSRC}/sample-plugins/${d}/* ${EXAMPLESDIR}/sample-plugins/${d}/
	@${RM} -rf ${WRKSRC}/contrib/${d}
. endfor
	@${INSTALL_DATA} ${WRKSRC}/sample-plugins/*.py ${EXAMPLESDIR}/sample-plugins/
	@${MKDIR} ${DATADIR}/cgi-bin
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/cgi-bin/* ${DATADIR}/cgi-bin
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
