# New ports collection makefile for:   orion
# Date created:        22 December 2000
# Whom:                Ernst de Haan <ernst@jollem.com>
#
# $FreeBSD$
#

PORTNAME=	orion
PORTVERSION=	1.4.5
PORTREVISION=	1
CATEGORIES=	java www
MASTER_SITES=	ftp://ftp.sunet.se/pub/database/utils/orionserver/ \
		http://www.jollem.com/
DISTNAME=	${PORTNAME}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		orion.sh${EXTRACT_SUFX}

MAINTAINER=	ernst@jollem.com

RUN_DEPENDS=	${LOCALBASE}/linux-jdk1.3.0/bin/java:${PORTSDIR}/java/linux-jdk13

USE_ZIP=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}
ORION_DESTDIR=	${PREFIX}/${DISTNAME}
ORION_LINKDIR=	${PREFIX}/${PORTNAME}
PORTTITLE=	Orion Server
RC_SCRIPT=	${PREFIX}/etc/rc.d/${PORTNAME}.sh

.include <bsd.port.pre.mk>

do-install:
	@if [ -d ${ORION_DESTDIR} ]; then \
		${ECHO} "ERROR: The destination directory ${ORION_DESTDIR} already exists. Cancelling."; \
		exit 65; \
	fi
	@if [ -L ${ORION_LINKDIR} ]; then \
		${ECHO} "WARNING: The link ${ORION_LINKDIR} already exists. Overwriting."; \
		/bin/ls -ld ${ORION_LINKDIR}; \
	else \
		if [ -e ${ORION_LINKDIR} ]; then \
			${ECHO} "ERROR: ${ORION_LINKDIR} already exists, and it's not a symlink. Cancelling."; \
			/bin/ls -ld ${ORION_LINKDIR}; \
			exit 66; \
		fi; \
	fi
	@if [ -e ${ORION_LINKDIR} ]; then \
		${ECHO} "WARNING: ${RC_SCRIPT} already exists. Overwriting."; \
	fi
	@${MKDIR} ${ORION_DESTDIR}
	@${CP} -R ${WRKSRC}/* ${ORION_DESTDIR}
	@${CP} ${WRKDIR}/orion.sh ${RC_SCRIPT}
	@if [ -e ${ORION_LINKDIR} ]; then \
		${RM} ${ORION_LINKDIR}; \
	fi
	@${LN} -sf ${ORION_DESTDIR} ${ORION_LINKDIR}

post-install:
	@echo "${PORTTITLE} ${PORTVERSION} has been installed in ${ORION_DESTDIR}."

.include <bsd.port.post.mk>
