# New ports collection makefile for:    ldapbrowser
# Date created:         17 August 2002
# Whom:                 Bruce M. Simpson
#
# $FreeBSD$
#

PORTNAME=	ldapbrowser
PORTVERSION=	2.8.1
CATEGORIES=	net java
MASTER_SITES=	http://www-unix.mcs.anl.gov/~gawor/ldapcommon/bin/
DISTNAME=	Browser281

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Java/Swing-based LDAP Browser/Editor

RESTRICTED=	"No reply from author regarding redistribution licensing"

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
NOMAN=		defined
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/lib/ldapbrowser
	cd ${WRKSRC} ; tar cf - . | ( cd ${PREFIX}/lib/ldapbrowser ; tar xf - )
	${SED} "s#^JH=.*#JH=${JAVA_HOME} ; cd ${PREFIX}/lib/ldapbrowser#" \
		< ${PREFIX}/lib/ldapbrowser/lbe.sh \
		> ${WRKDIR}/lbe.sh
	${INSTALL_SCRIPT} ${WRKDIR}/lbe.sh ${PREFIX}/bin/ldapbrowser

.include <bsd.port.mk>
