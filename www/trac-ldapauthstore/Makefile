# $FreeBSD$

PORTNAME=	ldapauthstore
PORTVERSION=	0.3.2.${SVN_REVISION}
CATEGORIES=	www devel python
MASTER_SITES=	LOCAL/matthew
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Trac AccountManager plugin using LDAP authentication store

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tracd:www/trac \
		trac-accountmanager>0:www/trac-accountmanager \
		trac-ldap>0:www/trac-ldap \
		${PYTHON_PKGNAMEPREFIX}ldap>0:net/py-ldap

NO_ARCH=	yes
PORTSCOUT=	ignore:1
SVN_REVISION=	15146

USES=		python:-2.7
USE_PYTHON=	distutils autoplist

# Maintainter targets below this point

# Retrieve the latest version from SVN and package in a tarball.
.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:devel/subversion
do-fetch:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && \
	    svn export --non-interactive \
		       --trust-server-cert-failures=unknown-ca \
		       --revision ${SVN_REVISION} \
		https://trac-hacks.org/svn/${PORTNAME}plugin/trunk/ \
	    ${DISTNAME}
	cd ${WRKDIR} && tar cvf ${DISTDIR}/${DISTNAME}.tar.gz ${DISTNAME}
.endif

.include <bsd.port.mk>
