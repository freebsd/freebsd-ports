# New ports collection makefile for:	limewire
# Date created:				Fri Feb 22 00:28:41 CST 2002
# Whom:					Kyle Martin <mkm@ieee.org> et al
#
# $FreeBSD$
#

PORTNAME=	limewire
PORTVERSION=	4.8.1
CATEGORIES=	net java
MASTER_SITES=	http://maverick.limewire.com/download/
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
		daap.jar i18n.jar icu4j.jar id3v2.jar jcraft.jar \
		jdic.jar jl011.jar jmdns.jar log4j.jar logicrypto.jar \
		looks.jar mp3sp14.jar themes.jar tritonus.jar \
		vorbis.jar xerces.jar xml-apis.jar xml.war update.ver \
		hashes libIdleTime.so libtray.so data.ser runLime.sh \
		MessagesBundle.properties spacer.gif donotremove.htm \
		root COPYING README.txt SOURCE

SUB_FILES=	limewire.sh
PLIST_FILES=	bin/limewire

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/limewire.sh ${PREFIX}/bin/limewire
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;

post-install:
	@cd ${WRKSRC} \
	  && ${FIND} -s ${DATAFILES} -type f | ${SED} 's,^,${DATADIR:S,^${PREFIX}/,,}/,' >>${TMPPLIST}
	@cd ${WRKSRC} \
	  && ${FIND} -s -d ${DATAFILES} -type d | ${SED} 's,^,@dirrm ${DATADIR:S,^${PREFIX}/,,}/,' >>${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${DATADIR:S,^${PREFIX}/,,}" >>${TMPPLIST}

.include <bsd.port.mk>
