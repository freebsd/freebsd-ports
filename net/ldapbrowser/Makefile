# New ports collection makefile for:    ldapbrowser
# Date created:         17 August 2002
# Whom:                 Bruce M. Simpson
#
# $FreeBSD$
#

PORTNAME=       ldapbrowser
PORTVERSION=    2.8.1
CATEGORIES=     net
MASTER_SITES=   http://www-unix.mcs.anl.gov/~gawor/ldapcommon/bin/
DISTNAME=	Browser281

MAINTAINER=     bms@FreeBSD.org
COMMENT=	Java/Swing-based LDAP Browser/Editor

RESTRICTED=	"No reply from author regarding redistribution licensing"
BROKEN=		"Creates a file in /"

USE_JAVA=	1.4+
NO_BUILD=	yes
NOMAN=		defined
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/lib/ldapbrowser
	cd ${WRKSRC} ; tar cf - . | ( cd ${PREFIX}/lib/ldapbrowser ; tar xf - )
	${SED} "s#^JH=.*#JH=${JAVA_HOME} ; cd ${PREFIX}/lib/ldapbrowser#" \
		< ${PREFIX}/lib/ldapbrowser/lbe.sh \
		> ${TMPDIR}/ldapbrowser
	${INSTALL_SCRIPT} ${TMPDIR}/ldapbrowser ${PREFIX}/bin

.include <bsd.port.mk>
