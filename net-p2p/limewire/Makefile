# New ports collection makefile for:	limewire
# Date created:				Fri Feb 22 00:28:41 CST 2002
# Whom:					Kyle Martin <mkm@ieee.org> et al
#
# $FreeBSD$
#

PORTNAME=	limewire
PORTVERSION=	4.2.5
CATEGORIES=	net java
MASTER_SITES=	http://www9.limewire.com:82/download/
DISTNAME=	LimeWireLinux
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Java based gnutella client

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

RESTRICTED=	License does not allow redistribution of any kind
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	LimeWire.jar MessagesBundle.properties MessagesBundles.jar \
		ProgressTabs.jar commons-httpclient.jar commons-logging.jar \
		daap.jar hashes i18n.jar icu4j.jar id3v2.jar jcraft.jar \
		jl011.jar jmdns.jar logicrypto.jar looks.jar mp3sp14.jar \
		themes.jar tritonus.jar update.ver vorbis.jar xerces.jar xml.war
PLIST_FILES=	bin/limewire ${DATAFILES:S,^,%%DATADIR%%/,}

post-patch:
	${SED} 's|%%DATADIR%%|${DATADIR}|; s|%%LOCALBASE%%|${LOCALBASE}|' \
		${FILESDIR}/limewire.sh > ${WRKSRC}/limewire

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/limewire ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DATAFILES} ${DATADIR}/

.include <bsd.port.mk>
