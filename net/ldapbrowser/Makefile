# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ldapbrowser
PORTVERSION=	2.8.2
PORTREVISION=	3
CATEGORIES=	net java
MASTER_SITES=	http://web.talf.org/software/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	Browser282b2

MAINTAINER=	ronald@echteman.nl
COMMENT=	Java/Swing-based LDAP browser and editor

RESTRICTED=	No reply from author regarding redistribution licensing

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NOMAN=		defined
WRKSRC=		${WRKDIR}/${PORTNAME}
REINPLACE_ARGS=	-i ''

NO_STAGE=	yes
post-extract:
	@${REINPLACE_CMD} -e 's|lbe\.jar|${PREFIX}/lib/ldapbrowser/lbe.jar|' \
		${WRKSRC}/lbe.sh

do-install:
	@${MKDIR} ${PREFIX}/lib/ldapbrowser
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} xf - -C ${PREFIX}/lib/ldapbrowser
	${ECHO_CMD} "#!/bin/sh" > ${PREFIX}/bin/ldapbrowser
	${ECHO_CMD} "${PREFIX}/lib/ldapbrowser/lbe.sh -base ${PREFIX}/lib/ldapbrowser" >> ${PREFIX}/bin/ldapbrowser
	${CHMOD} +x ${PREFIX}/bin/ldapbrowser

.include <bsd.port.mk>
