# Ports collection makefile for:  ipplan
# Date created:			  26 Nov 2004
# Whom:				  Maxim Tuliuk <mt@primats.org.ua>
#
# $FreeBSD$
#

PORTNAME=	ipplan
PORTVERSION=	4.3.1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	iptrack
DISTNAME=	${PORTNAME}-4.31

MAINTAINER=	mt@primats.org.ua
COMMENT=	IP address management and tracking

USE_REINPLACE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
IPPLANDIR?=	share/${PORTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	IPPLANDIR=${IPPLANDIR}

USE_PHP=	gettext pcre xml zlib

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_SNMP)
USE_PHP+=	snmp
.endif

post-patch:
	@${SED} -e 's|%IPPLANDIR%|${PREFIX}/${IPPLANDIR}|g' ${MASTERDIR}/pkg-message > ${PKGMESSAGE}
.if defined(WITH_PGSQL)
	@${REINPLACE_CMD} -e 's|INSTALL|INSTALL-POSTGRESQL|g' ${PKGMESSAGE}
.endif

do-install:
	@${MKDIR} ${PREFIX}/${IPPLANDIR}
	@${CP} -R ${WRKSRC}/* ${PREFIX}/${IPPLANDIR}
	@${FIND} ${PREFIX}/${IPPLANDIR} -name '*.orig' -delete
	@${CAT} ${PKGMESSAGE}

post-install:
	@${MKDIR} -m 700 /var/spool/ipplan/uploads \
		/var/spool/ipplan/exportdns
	@${CHOWN} -R www:www /var/spool/ipplan

.include <bsd.port.mk>
