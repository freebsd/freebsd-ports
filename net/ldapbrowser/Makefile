# New ports collection makefile for:    ldapbrowser
# Date created:         17 August 2002
# Whom:                 Bruce M. Simpson
#
# $FreeBSD$
#

PORTNAME=	ldapbrowser
PORTVERSION=	2.8.2
PORTREVISION=	2
CATEGORIES=	net java
MASTER_SITES=	http://www.mcs.anl.gov/~gawor/ldapcommon/bin/ \
		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}/sources/
DISTNAME=	Browser282b2

MAINTAINER=	ronald@echteman.nl
COMMENT=	Java/Swing-based LDAP Browser/Editor

RESTRICTED=	No reply from author regarding redistribution licensing

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
NOMAN=		defined
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/lib/ldapbrowser
	cd ${WRKSRC} ; tar cf - . | ( cd ${PREFIX}/lib/ldapbrowser ; tar xf - )
	${ECHO_CMD} "cd ${PREFIX}/lib/ldapbrowser" > ${PREFIX}/bin/ldapbrowser
	${ECHO_CMD} "sh ${PREFIX}/lib/ldapbrowser/lbe.sh" >> ${PREFIX}/bin/ldapbrowser
	${CHMOD} +x ${PREFIX}/bin/ldapbrowser

.include <bsd.port.mk>
