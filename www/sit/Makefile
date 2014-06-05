# Created by: Carsten Jensen <carsten@sitracker.org>
# $FreeBSD$

PORTNAME=	sit
PORTVERSION=	3.67
CATEGORIES=	www
MASTER_SITES=	SF/sitracker/stable/${PORTVERSION}/
DISTNAME=	sit_${PORTVERSION}p1

MAINTAINER=	carsten@sitracker.org
COMMENT=	A PHP incident tracking system / Helpdesk

LICENSE=	GPLv2

USE_PHP=	pcre mysql session zlib mbstring
WANT_PHP_WEB=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/sit-${PORTVERSION}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	IMAP MBSTRING LDAP
OPTIONS_DEFAULT=	IMAP MBSTRING
IMAP_DESC=	Email Support
MBSTRING_DESC=	Inbound email feature

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAP}
USE_PHP+=	imap
.endif

.if ${PORT_OPTIONS:MMBSTRING}
USE_PHP+=	mbstring
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	${CHMOD} -R ${BINMODE} ${STAGEDIR}${WWWDIR}
	${FIND} ${STAGEDIR}${WWWDIR} ! -type d | ${XARGS} ${CHMOD} ${NOBINMODE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
