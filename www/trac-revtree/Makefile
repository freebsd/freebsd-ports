# New ports collection makefile for: trac-revtree
# Date created:                      Nov 10 2008
# Whom:                              glarkin
#
# $FreeBSD$
#

PORTNAME=	revtree
PORTVERSION=	0.6.4
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Graphical representation of an SVN repository

RUN_DEPENDS+=	trac>=0.12:${PORTSDIR}/www/trac \
		subversion>=0:${PORTSDIR}/devel/subversion

OPTIONS=	MINFOENH "Enable mergeinfo display enhancer" On \
		LOGENH "Enable log message display enhancer" Off

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.12
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracRevtreePlugin
PYDISTUTILS_PKGVERSION=	${PORTVERSION}dev
PLIST_SUB+=	EGGVERSION="${PORTVERSION}dev" PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MINFOENH)
MINFOENH_VERSION=	0.2.1
PLIST_SUB+=	MINFOENH_EGGVERSION="${MINFOENH_VERSION}dev"
ENH1=""
.else
ENH1="@comment "
.endif
PLIST_SUB+=	ENH1=${ENH1}

.if defined(WITH_LOGENH)
LOGENH_VERSION=		0.2.0
PLIST_SUB+=	LOGENH_EGGVERSION="${LOGENH_VERSION}dev"
ENH2=""
.else
ENH2="@comment "
.endif
PLIST_SUB+=	ENH2=${ENH2}

post-install:
# Install the selected enhancer plugins
.if defined(WITH_MINFOENH)
	@( cd ${WRKSRC}/enhancers/mergeinfoenhancer ; \
		${PYEASYINSTALL_CMD} . )
.endif
.if defined(WITH_LOGENH)
	@( cd ${WRKSRC}/enhancers/logenhancer ; \
		${PYEASYINSTALL_CMD} . )
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
