#
# ports collection makefile for:	mysar
# Whom:					Edwin Groothuis <edwin@mavetju.org>
# Date created:				2006-01-10
#
# $FreeBSD$
#

PORTNAME=	mySAR
PORTVERSION=	2.1.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	MySQL Squid Access Report

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

WRKROOT=	${WRKDIR}/${PORTNAME:L}
WRKSRC=		${WRKROOT}/bin/mysar-binary-importer/
GNU_CONFIGURE=	yes
USE_MYSQL=	yes
USE_PHP=	mysql pcre

CONFIGURE_ARGS=	--with-mysql-lib=${LOCALBASE}

MYSARPREFIX=	mysar
MYSARDIR?=	${PREFIX}/${MYSARPREFIX}
PLIST_SUB=	MYSAR=${MYSARPREFIX}

SUB_FILES=	pkg-message
SUB_LIST=	MYSARDIR=${MYSARDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	${CHMOD} +x ${WRKSRC}/config/*

post-patch:
	${REINPLACE_CMD} \
		-e 's,/usr/local/mysar/,${MYSARDIR},g' \
		${WRKROOT}/etc/mysar.cron
	${REINPLACE_CMD} \
		-e 's,/usr/local/mysar/,${MYSARDIR},g' \
		${WRKROOT}/etc/mysar.apache

	${REINPLACE_CMD} \
		-e 's,%%MYSARDIR%%,${MYSARDIR},g' \
		`find ${WRKROOT}/etc -type f`
	${REINPLACE_CMD} \
		-e 's,%%PHP%%,${LOCALBASE}/bin/php,g' \
		`find ${WRKROOT}/bin -type f`
	${REINPLACE_CMD} \
		-e 's,/bin/sh,${LOCALBASE}/bin/bash,g' \
		`find ${WRKROOT}/bin/mysar-binary-importer -type f`

	${FIND} ${WRKROOT} -name *.orig -delete
	${FIND} ${WRKROOT} -name *.bak -delete

do-install:
	${MV} ${WRKSRC} ${WRKROOT}
	${MKDIR} ${MYSARDIR}
	${CP} -R `find ${WRKROOT} -mindepth 1 -maxdepth 1 ! -name mysar-binary-importer` ${MYSARDIR}
	${INSTALL_PROGRAM} ${WRKROOT}/mysar-binary-importer/src/mysar ${MYSARDIR}/bin
	${INSTALL_DATA} ${WRKROOT}/mysar-binary-importer/mysar.conf ${MYSARDIR}/etc
	${CHOWN} -R ${WWWOWN} ${MYSARDIR}/www-templates
	${CHOWN} -R ${WWWOWN} ${MYSARDIR}/smarty-tmp

	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
