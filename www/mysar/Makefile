# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	mySAR
PORTVERSION=	2.1.4
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MySQL Squid Access Report

LICENSE=	GPLv2
LICENSE_FILE=	${WRKROOT}/COPYING

BUILD_DEPENDS=	bash:shells/bash

WRKROOT=	${WRKDIR}/${PORTNAME:tl}
WRKSRC=		${WRKROOT}/bin/mysar-binary-importer
GNU_CONFIGURE=	yes
USE_MYSQL=	yes
USE_PHP=	mysql pcre
USE_CSTD=	gnu89

CONFIGURE_ARGS=	--with-mysql-lib=${LOCALBASE}

MYSARPREFIX=	mysar
MYSARDIR?=	${PREFIX}/${MYSARPREFIX}
PLIST_SUB=	MYSAR=${MYSARPREFIX} WWWOWN="${WWWOWN}"

SUB_FILES=	pkg-message
SUB_LIST=	MYSARDIR=${MYSARDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	@${CHMOD} +x ${WRKSRC}/config/*

post-patch:
	@${REINPLACE_CMD} \
		-e 's,/usr/local/mysar/,${MYSARDIR},g' \
		${WRKROOT}/etc/mysar.cron
	@${REINPLACE_CMD} \
		-e 's,/usr/local/mysar/,${MYSARDIR},g' \
		${WRKROOT}/etc/mysar.apache

	@${REINPLACE_CMD} \
		-e 's,/usr/bin/php,${LOCALBASE}/bin/php,g' \
		-e 's,\([=,. ]\)mktime(),\1time(),g' \
		`find ${WRKROOT}/bin -type f`
	@${REINPLACE_CMD} \
		-e 's,/bin/sh,${LOCALBASE}/bin/bash,g' \
		`find ${WRKROOT}/bin/mysar-binary-importer -type f`

	@${FIND} ${WRKROOT} -name *.orig -delete
	@${FIND} ${WRKROOT} -name *.bak -delete

do-install:
	${MV} ${WRKSRC} ${WRKROOT}
	${MKDIR} ${STAGEDIR}${MYSARDIR}
	${CP} -R `find ${WRKROOT} -mindepth 1 -maxdepth 1 ! -name mysar-binary-importer` ${STAGEDIR}${MYSARDIR}
	${INSTALL_PROGRAM} ${WRKROOT}/mysar-binary-importer/src/mysar ${STAGEDIR}${MYSARDIR}/bin
	${INSTALL_DATA} ${WRKROOT}/mysar-binary-importer/mysar.conf ${STAGEDIR}${MYSARDIR}/etc

.include <bsd.port.mk>
