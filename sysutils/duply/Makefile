# Created by: Michael Ranner <michael@ranner.eu>
# $FreeBSD$

PORTNAME=	duply
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://duply.net/projects/ftplicity/files/duply%20%28simple%20duplicity%29/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}.x/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	michael@ranner.eu
COMMENT=	Shell front end for the duplicity backup tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl-2.0.txt

RUN_DEPENDS=	duplicity:sysutils/duplicity \
		bash:shells/bash

USES=		python tar:tgz

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/duply ${PERIODICDIR}/${PERIODICFILE}
PERIODICFILE?=	300.duply
PERIODICDIR?=	${PREFIX}/etc/periodic/backup
SUB_FILES=	pkg-message periodic_duply

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s,/etc/duply,${ETCDIR},g" ${WRKSRC}/duply

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/duply ${STAGEDIR}${PREFIX}/bin/duply
	@${MKDIR} ${STAGEDIR}${PERIODICDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/periodic_duply ${STAGEDIR}${PERIODICDIR}/${PERIODICFILE}

.include <bsd.port.mk>
