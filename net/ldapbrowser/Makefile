# New ports collection makefile for:    ldapbrowser
# Date created:         17 August 2002
# Whom:                 Bruce M. Simpson
#
# $FreeBSD$
#

PORTNAME=	ldapbrowser
PORTVERSION=	2.8.2
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}/sources/ \
		http://www.klop.ws/~ronald/software-mirrors/
DISTNAME=	Browser282b2

MAINTAINER=	ronald@echteman.nl
COMMENT=	Java/Swing-based LDAP browser/editor

RESTRICTED=	No reply from author regarding redistribution licensing

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
NOMAN=		defined
WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
	@${REINPLACE_CMD} -i '' -e 's|lbe.jar|${PREFIX}/lib/ldapbrowser/lbe.jar|' ${WRKSRC}/lbe.sh

do-install:
	${MKDIR} ${PREFIX}/lib/ldapbrowser
	cd ${WRKSRC} ; tar cf - . | ( cd ${PREFIX}/lib/ldapbrowser ; tar xf - )
	${ECHO_CMD} "#!/bin/sh" > ${PREFIX}/bin/ldapbrowser
	${ECHO_CMD} "${PREFIX}/lib/ldapbrowser/lbe.sh -base ${PREFIX}/lib/ldapbrowser" >> ${PREFIX}/bin/ldapbrowser
	${CHMOD} +x ${PREFIX}/bin/ldapbrowser

.include <bsd.port.mk>
