# New ports collection makefile for:	ilohamail
# Date created:		2004-01-20
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	ilohamail
PORTVERSION=	0.8.13
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/IlohaMail-stable/${PORTVERSION}
DISTNAME=	IlohaMail-${PORTVERSION}

MAINTAINER=	tota@rtfm.jp
COMMENT=	IlohaMail is a lightweight multilingual webmail program

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if !defined(WITHOUT_WWWDIR)
ILOHADIR=	${PREFIX}/www/ilohamail
.else
ILOHADIR=	${PREFIX}/ilohamail
.endif

PLIST_SUB+=	ILOHADIR="${ILOHADIR:S,^${PREFIX}/,,}"
PKGMESSAGE=	${WRKDIR}/pkg-message

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  define WITHOUT_MYSQL: not to use MySQL back-end"
	@${ECHO_MSG} ""

do-install:
	@${MKDIR} ${ILOHADIR}
	${CP} -Rp ${WRKSRC}/IlohaMail/ ${ILOHADIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${ILOHADIR}/data
.if !defined(WITHOUT_MYSQL)
	@${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/MySQL ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${CP} -Rp INSTALL README RELEASE_NOTES \
		THEMES TODO UPGRADING Manual ${DOCSDIR}
.endif

post-install:
	@${SED} -e 's|%%ILOHADIR%%|${ILOHADIR}|g' \
		-e 's|%%DATADIR%%|${DATADIR}|g' \
		-e 's|%%DOCSDIR%%|${DOCSDIR}|g' \
		< ${MASTERDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
