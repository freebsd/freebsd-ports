# New ports collection Makefile for:	davmail
# Date created:				28 Oct 2010
# Whom:					John Prather
#
# $FreeBSD$
#

PORTNAME=	davmail
PORTVERSION=	3.9.9
CATEGORIES=	mail java
MASTER_SITES=	SF/davmail/davmail/${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}-${REVISION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	john.c.prather@gmail.com
COMMENT=	POP/IMAP/SMTP/Caldav/Carddav/LDAP Exchange Gateway

LICENSE=	GPLv2

RUN_DEPENDS=	swt>=3.5:${PORTSDIR}/x11-toolkits/swt

USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
ALL_TARGET=	release
REVISION=	1976
# port build number, same as on DISTNAME
MAKE_ARGS=	-Drevision=${REVISION}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USE_RC_SUBR=	davmail
SUB_FILES=	davmail.sh

post-patch:
	@${REINPLACE_CMD} -e 's#exec=\"davmail\"#exec=\"${PREFIX}/bin/davmail\"#' \
		-e 's#icon=\"/usr/share/davmail/davmail.png\"#icon=\"${DATADIR}/davmail.png\"#' \
		${WRKSRC}/build.xml

do-install:
	@cd ${WRKSRC}/dist && ${FIND} . -type d \
		-exec ${MKDIR} ${DATADIR}/\{} \;
	@cd ${WRKSRC}/dist && ${FIND} . -type f \
		-not -name "*.deb" \
		-not -name "*.tgz" \
		-not -name "*.exe" \
		-not -name "swt-*.jar" \
		-not -name "*.zip" \
		-not -name "*.war" \
		-not -name "*.rpm" \
		-not -name "*.desktop" \
		-exec ${INSTALL_DATA} \{} ${DATADIR}/\{} \;
	@${INSTALL_SCRIPT} ${WRKDIR}/davmail.sh ${PREFIX}/bin/davmail
	@${INSTALL_DATA} ${FILESDIR}/davmail.properties.sample \
		${PREFIX}/etc
	@${MKDIR} ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/dist/davmail.desktop ${PREFIX}/share/applications/

post-install:
	@if [ ! -f ${PREFIX}/etc/davmail.properties ]; then \
		${CP} -p ${PREFIX}/etc/davmail.properties.sample \
			${PREFIX}/etc/davmail.properties ; \
	fi

.include <bsd.port.mk>
