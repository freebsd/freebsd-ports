# New ports collection makefile for:	ilohamail
# Date created:		2004-01-20
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	ilohamail
PORTVERSION=	0.8.12
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ilohamail
DISTNAME=	IlohaMail-${PORTVERSION}

MAINTAINER=	tota@rtfm.jp
COMMENT=	IlohaMail is a lightweight multilingual webmail program

NO_BUILD=	yes
USE_PHP=	yes
WANT_PHP_WEB=	yes

.if !defined(WITHOUT_WWWDIR)
ILOHADIR=	${PREFIX}/www/ilohamail
.else
ILOHADIR=	${PREFIX}/ilohamail
.endif

PLIST_SUB+=	ILOHADIR="${ILOHADIR:S,^${PREFIX}/,,}"
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	@${MKDIR} ${ILOHADIR}
	${CP} -Rp ${WRKSRC}/IlohaMail/ ${ILOHADIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${ILOHADIR}/data
	@${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/MySQL ${DATADIR}
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
