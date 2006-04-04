# New ports collection makefile for:	www/joomla
# Date created:				Sat Out 15, 2005
# Whom:					Francisco Cabrita <include@npf.pt.freebsd.org>
#
# $FreeBSD$

PORTNAME=	joomla
PORTVERSION=	1.0.8
CATEGORIES=	www
MASTER_SITES=	http://forge.joomla.org/sf/frs/do/downloadFile/projects.joomla/frs.joomla_1_0.1_0_8/frs3902?dl=1/:source1
DISTFILES=	${JOOMLA_SRC}:source1

MAINTAINER=	include@npf.pt.freebsd.org
COMMENT=	A dynamic web content management system (CMS)

NO_BUILD=	yes
USE_MYSQL=	yes
USE_PHP=	mysql pcre xml zlib session gd pdf
WANT_PHP_WEB=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST+=	JOOMLA_DIR=${JOOMLA_DIR}
PLIST_SUB+=	JOOMLA_DIR=${JOOMLA_DIR}

JOOMLA_DIR?=	www/${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

JOOMLA_SRC=	Joomla_${PORTVERSION}-Stable-Full_Package.tar.bz2

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -yxf ${DISTDIR}/${DIST_SUBDIR}/${JOOMLA_SRC} -C ${WRKSRC}

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
