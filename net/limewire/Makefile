# New ports collection makefile for:	limewire
# Date created:				Fri Feb 22 00:28:41 CST 2002
# Whom:					Kyle Martin <mkm@ieee.org> et al
#
# $FreeBSD$
#

PORTNAME=	limewire
PORTVERSION=	3.6.15
PORTREVISION=	1
CATEGORIES=	net java
MASTER_SITES=	http://www3.limewire.com/download/
DISTNAME=	LimeWireLinux
EXTRACT_SUFX=	.tgz

MAINTAINER=	past@noc.ntua.gr
COMMENT=	A Java based gnutella client

USE_JAVA=	1.3+
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

RESTRICTED=	License does not allow redistribution of any kind
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

JAR_DIR=	${PREFIX}/share/java/jar/limewire
PLIST_SUB=	JAR_DIR="${JAR_DIR:S/${PREFIX}\///}"

post-patch:
	@${SED} 's|%%JAR_DIR%%|${JAR_DIR}|; s|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/runLime.sh > ${WRKSRC}/runLime.sh.sed

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/runLime.sh.sed ${PREFIX}/bin/limewire
	@${MKDIR} ${JAR_DIR}
	@${INSTALL_DATA} ${WRKSRC}/*.jar ${WRKSRC}/MessagesBundle.properties \
		${WRKSRC}/xml.war ${WRKSRC}/update.ver ${JAR_DIR}

.include <bsd.port.mk>
