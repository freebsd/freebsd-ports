# New ports collection makefile for:	davmail
# Date created:				28 Oct 2010
# Whom:					John Prather
#
# $FreeBSD$
#

PORTNAME=	davmail
PORTVERSION=	3.8.7
CATEGORIES=	mail java
MASTER_SITES=	SF/davmail/davmail/${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}-1558
EXTRACT_SUFX=	.tgz

MAINTAINER=	john.c.prather@gmail.com
COMMENT=	POP/IMAP/SMTP/Caldav/Carddav/LDAP Exchange Gateway

RUN_DEPENDS=	swt>=3.5:${PORTSDIR}/x11-toolkits/swt

USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

post-build:
	${CP} ${FILESDIR}/davmail.sh.in ${WRKDIR}/davmail.sh
	${REINPLACE_CMD} -e "s|%BASE%|${DATADIR}|" \
			-e "s|%JAVASHAREDIR%|${JAVASHAREDIR}|" \
		${WRKDIR}/davmail.sh

do-install:
	cd ${WRKSRC}/dist && ${FIND} . -type d \
		-exec ${MKDIR} ${DATADIR}/\{} \;
	cd ${WRKSRC}/dist && ${FIND} . -type f \
		-not -name "*.deb" \
		-not -name "*.tgz" \
		-not -name "*.exe" \
		-not -name "swt-*.jar" \
		-not -name "*.zip" \
		-not -name "*.war" \
		-not -name "*.rpm" \
		-exec ${INSTALL_DATA} \{} ${DATADIR}/\{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/davmail.sh ${PREFIX}/bin/davmail

.include <bsd.port.mk>
