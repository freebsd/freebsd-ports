# New ports collection makefile for:   orion
# Date created:        22 December 2000
# Whom:                Ernst de Haan <ernst@jollem.com>
#
# $FreeBSD$
#

PORTNAME=	orion
PORTVERSION=	1.4.5
PORTREVISION=	3
CATEGORIES=	java www
MASTER_SITES=	ftp://ftp.sunet.se/pub/database/utils/orionserver/ \
		${MASTER_SITE_LOCAL} \
		http://www.jollem.com/ \
		http://www.sebster.com/~elvis/
MASTER_SITE_SUBDIR=	sobomax
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ernst@jollem.com

RUN_DEPENDS=	${LOCALBASE}/linux-jdk1.3.0/bin/java:${PORTSDIR}/java/linux-jdk13

USE_ZIP=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}
ORION_DESTDIR=	${PREFIX}/${DISTNAME}
PORTTITLE=	Orion Server
ORIONCTL_NAME=	orionctl
ORIONCTL_DEST=	${PREFIX}/bin/${ORIONCTL_NAME}
RC_SCRIPT=	${PREFIX}/etc/rc.d/${PORTNAME}.sh

.include <bsd.port.pre.mk>

do-install:
	@if [ -d ${ORION_DESTDIR} ]; then \
		${ECHO} "ERROR: The destination directory ${ORION_DESTDIR} already exists. Cancelling."; \
		exit 65; \
	fi
	@${MKDIR} ${ORION_DESTDIR}
	@${CP} -R ${WRKSRC}/* ${ORION_DESTDIR}
	@${CHMOD} 755 `find ${ORION_DESTDIR} -type d`
	@${CP} ${FILESDIR}/${ORIONCTL_NAME}  ${ORIONCTL_DEST}
	@${CHMOD} 755 ${ORIONCTL_DEST}
	@${LN} -s ${ORIONCTL_DEST} ${RC_SCRIPT}
	@${MKDIR} ${ORION_DESTDIR}/application-deployments

post-install:
	@echo "${PORTTITLE} ${PORTVERSION} has been installed in ${ORION_DESTDIR}."

.include <bsd.port.post.mk>
