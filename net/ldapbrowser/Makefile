# Created by: Bruce M. Simpson <bms@FreeBSD.org>

PORTNAME=	ldapbrowser
PORTVERSION=	2.8.2
PORTREVISION=	4
CATEGORIES=	net java
MASTER_SITES=	http://www.klop.ws/distfiles/ \
		http://freebsd.nsu.ru/distfiles/ \
		ftp://ftp.nstu.ru/pub/sources/nettools/ldap/ \
		ftp://ftp.gtrgrenoble.fr/TpRes/Ldap/ \
		ftp://ftp.uni-duisburg.de/Unix/networking/LDAP/frontends/
DISTNAME=	Browser282b2

MAINTAINER=	ronald-lists@klop.ws
COMMENT=	Java/Swing-based LDAP browser and editor

# Converted from RESTRICTED
LICENSE=	ldapbrowser-license
LICENSE_NAME=	ldapbrowser
LICENSE_TEXT=	No reply from author regarding redistribution licensing
LICENSE_PERMS=	auto-accept

USE_JAVA=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
REINPLACE_ARGS=	-i ''

post-extract:
	@${REINPLACE_CMD} -e 's|lbe\.jar|${PREFIX}/lib/ldapbrowser/lbe.jar|' \
		${WRKSRC}/lbe.sh

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ldapbrowser
	${TAR} -C ${WRKSRC} -cf - . | ${TAR} xf - -C ${STAGEDIR}${PREFIX}/lib/ldapbrowser
	${ECHO_CMD} "#!/bin/sh" > ${STAGEDIR}${PREFIX}/bin/ldapbrowser
	${ECHO_CMD} "${PREFIX}/lib/ldapbrowser/lbe.sh -base ${PREFIX}/lib/ldapbrowser" >> ${STAGEDIR}${PREFIX}/bin/ldapbrowser
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/ldapbrowser

.include <bsd.port.mk>
