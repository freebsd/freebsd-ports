# New ports collection Makefile for: sysutils/phplogcon
# Date created:	        21 December 2008
# Whom:                 Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	phplogcon
PORTVERSION=	2.5.23
CATEGORIES=	sysutils www
MASTER_SITES=	http://download.adiscon.com/phplogcon/

MAINTAINER=	cristianorolim@hotmail.com
COMMENT=	Web Based Syslog Review

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	YES
WANT_PHP_WEB=	YES
.endif
NO_BUILD=	YES
LOGCONDIR?=	www/phplogcon
PLIST_SUB+=	LOGCONDIR=${LOGCONDIR}

pre-everything::
	@${ECHO_CMD} "# you can customize the installation directory"
	@${ECHO_CMD} "# by setting LOGCON in /etc/make.conf"

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/${LOGCONDIR}
	${CP} -Rp ${WRKSRC}/src/ ${PREFIX}/${LOGCONDIR}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/* ${DATADIR}
.endif

.include <bsd.port.post.mk>
