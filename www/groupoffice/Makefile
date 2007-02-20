# New ports collection makefile for:	www/groupoffice
# Date created:							16 February 2007
# Whom:					Aron Schlesinger <as@bsdgroup.de>
#
# $FreeBSD$

PORTNAME=	groupoffice
PORTVERSION=	2.16.11
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	group-office
DISTNAME=	${PORTNAME}-com-2.16-11

MAINTAINER=	as@bsdgroup.de
COMMENT=	A modular web application framework vor office

RESTRICTED=	Free for personal use only

NO_BUILD=	yes

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	mysql session mbstring pcre xml
.endif

WANT_PHP_WEB=	yes
USE_MYSQL=	yes
IGNORE_WITH_MYSQL=	323

OPTIONS=	IMAP "IMAP support" on

PORT_DBDIR?=	${DESTDIR}/var/db/ports
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

.if !defined(WITHOUT_PHP_DEPENDS)
.	if !defined(WITHOUT_IMAP) || defined(WITH_IMAP)
USE_PHP+=	imap
.	endif
.endif

GROUPOFFICEDIR?=	www/${PORTNAME}2

SUB_FILES=	pkg-message
SUB_LIST=	"GROUPOFFICEDIR=${GROUPOFFICEDIR}" \
			"PKGNAME=${PKGNAME}" \
			"WWWOWN=${WWWOWN}"

pre-everything::
	@${ECHO_CMD} "# you can customize the installation directory"
	@${ECHO_CMD} "# by setting GROUPOFFICEDIR in /etc/make.conf"

do-install:
	@${MKDIR} ${PREFIX}/${GROUPOFFICEDIR}
	${CP} -r ${WRKSRC}/ ${PREFIX}/${GROUPOFFICEDIR}

post-install:
	@${FIND} ${WRKSRC}/${file} -not -type d \
		| ${SED} -ne 's,^${WRKSRC},${GROUPOFFICEDIR},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${file} -type d \
		| ${SED} -ne 's,^${WRKSRC},@dirrm ${GROUPOFFICEDIR},p' >> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
