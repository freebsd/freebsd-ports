# Created by: Carsten Jensen <carsten@sitracker.org>
# $FreeBSD$

PORTNAME=	sit
PORTVERSION=	3.67
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/sitracker/stable/${PORTVERSION}/
DISTNAME=	sit_${PORTVERSION}p1

MAINTAINER=	carsten@sitracker.org
COMMENT=	PHP incident tracking system / Helpdesk

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

USE_PHP=	pcre mysql session zlib mbstring
WANT_PHP_WEB=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/sit-${PORTVERSION}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	IMAP MBSTRING LDAP
OPTIONS_DEFAULT=	IMAP MBSTRING
IMAP_DESC=	Email Support
MBSTRING_DESC=	Inbound email feature

IMAP_USE=	PHP=imap
MBSTRING_USE=	PHP=mbstring
LDAP_USE=	PHP=ldap

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	${CHMOD} -R ${BINMODE} ${STAGEDIR}${WWWDIR}
	${FIND} ${STAGEDIR}${WWWDIR} ! -type d | ${XARGS} ${CHMOD} ${NOBINMODE}

.include <bsd.port.mk>
