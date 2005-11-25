# New ports collection makefile for:	www/joomla
# Date created:				Sat Out 15, 2005
# Whom:					Francisco Cabrita <include@npf.pt.freebsd.org>
#
# $FreeBSD$

PORTNAME=	joomla
PORTVERSION=	1.0.3
CATEGORIES=	www
MASTER_SITES=	http://developer.joomla.org/sf/frs/do/downloadFile/projects.joomla/frs.joomla_1_0.1_0_3/frs1820?dl=1/:source1
DISTFILES=	${JOOMLA_SRC}:source1

MAINTAINER=	include@npf.pt.freebsd.org
COMMENT=	A dynamic web content management system (CMS)

NO_BUILD=	yes
USE_MYSQL=	yes
USE_PHP=	mysql zlib
WANT_PHP_WEB=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST+=	JOOMLA_DIR=${JOOMLA_DIR}
PLIST_SUB+=	JOOMLA_DIR=${JOOMLA_DIR}

JOOMLA_DIR?=	www/${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

JOOMLA_SRC=	Joomla_1.0.3-Stable-Full_Package.tar.gz

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -zxf ${DISTDIR}/${DIST_SUBDIR}/${JOOMLA_SRC} -C ${WRKSRC}
	@${RM} -rf ${WRKSRC}/templates/rhuk_solarflare # remove empty

do-install:
	@${MKDIR} ${PREFIX}/${JOOMLA_DIR}
	@cd ${WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} ${PREFIX}/${JOOMLA_DIR}/{} \; \
			-exec ${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${JOOMLA_DIR}/{} \;
	@cd ${WRKSRC} && \
		${FIND} . \! -type d -exec ${INSTALL_DATA} {} ${PREFIX}/${JOOMLA_DIR}/{} \; \
			-exec ${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${JOOMLA_DIR}/{} \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
