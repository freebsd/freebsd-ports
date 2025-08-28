PORTNAME=	ldapbrowser
PORTVERSION=	2.8.2
PORTREVISION=	6
CATEGORIES=	net java
MASTER_SITES=	LOCAL/ronald \
		https://www.klop.ws/distfiles/ \
		http://freebsd.nsu.ru/distfiles/ \
		ftp://ftp.nstu.ru/pub/sources/nettools/ldap/ \
		ftp://ftp.gtrgrenoble.fr/TpRes/Ldap/ \
		ftp://ftp.uni-duisburg.de/Unix/networking/LDAP/frontends/
DISTNAME=	Browser282b2

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Java/Swing-based LDAP browser and editor
WWW=		https://web.archive.org/web/20081218031210/http://www.mcs.anl.gov/~gawor/ldap/

# Converted from RESTRICTED
LICENSE=	ldapbrowser-license
LICENSE_NAME=	ldapbrowser
LICENSE_TEXT=	No reply from author regarding redistribution licensing
LICENSE_PERMS=	auto-accept

USES=		java

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
