# New ports collection makefile for:	limewire
# Date created:				Fri Feb 22 00:28:41 CST 2002
# Whom:					Kyle Martin <mkm@ieee.org> et al
#
# $FreeBSD$
#

PORTNAME=	limewire
PORTVERSION=	4.8.0
CATEGORIES=	net java
MASTER_SITES=	http://www9.limewire.com:82/download/4.8.0/
DISTNAME=	LimeWireOther

MAINTAINER=	ports@edini.net
COMMENT=	A Java based gnutella client

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/LimeWire

RESTRICTED=	License does not allow redistribution of any kind
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	LimeWire.jar MessagesBundles.jar ProgressTabs.jar \
		clink.jar commons-httpclient.jar commons-logging.jar \
		daap.jar hashes i18n.jar icu4j.jar id3v2.jar jcraft.jar \
		jl011.jar jmdns.jar log4j.jar logicrypto.jar looks.jar \
		mp3sp14.jar themes.jar tritonus.jar update.ver vorbis.jar \
		xerces.jar xml-apis.jar xml.war \
		data.ser MessagesBundle.properties libIdleTime.so \
		pub1.key spacer.gif donotremove.htm \
		COPYING README.txt SOURCE
PLIST_FILES=	bin/limewire ${DATAFILES:S,^,%%DATADIR%%/,}
PLIST_DIRS=	%%DATADIR%%

SUB_FILES=	limewire.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/limewire.sh ${PREFIX}/bin/limewire
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DATAFILES} ${DATADIR}/

.include <bsd.port.mk>
