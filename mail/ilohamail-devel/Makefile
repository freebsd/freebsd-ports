# New ports collection makefile for:	ilohamail-devel
# Date created:		3 April 2007
# Whom:			craig001@lerwick.hopto.org
#
# $FreeBSD$
#

PORTNAME=	ilohamail-devel
PORTVERSION=	0.9.20050415
CATEGORIES=	mail www
MASTER_SITES=	SF/ilohamail/IlohaMail-devel/0.9-20050415
DISTNAME=	IlohaMail-0.9-20050415

MAINTAINER=	craig001@lerwick.hopto.org
COMMENT=	IlohaMail is a lightweight webmail program (devel version)

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
ILOHADIR=	${PREFIX}/www/ilohamail-devel
.else
ILOHADIR=	${PREFIX}/ilohamail-devel
.endif

PLIST_SUB+=	ILOHADIR="${ILOHADIR:S,^${PREFIX}/,,}"
SUB_FILES+=	pkg-message
SUB_LIST+=	ILOHADIR=${ILOHADIR}

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  define WITHOUT_MYSQL: not to use MySQL back-end"
	@${ECHO_MSG} ""

do-install:
	@${MKDIR} ${ILOHADIR}
	${CP} -Rp ${WRKSRC}/IlohaMail/ ${ILOHADIR}
	@${MKDIR} ${ILOHADIR}/data
	@${MKDIR} ${ILOHADIR}/data/users
	@${MKDIR} ${ILOHADIR}/data/sessions
	@${MKDIR} ${ILOHADIR}/data/cache
	@${MKDIR} ${ILOHADIR}/data/uploads
	@${MKDIR} ${ILOHADIR}/data/gpg
#	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${ILOHADIR}/data
.if !defined(WITHOUT_MYSQL)
	@${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/MySQL ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && \
		${CP} -Rp INSTALL README RELEASE_NOTES \
		THEMES TODO UPGRADING Manual ${DOCSDIR}
.endif

post-install:
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${ILOHADIR}/data
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
