# New ports collection makefile for:	paros
# Date created:				25 June 2007
# Whom:					Wesley Shields <wxs@atarininja.org>
#
# $FreeBSD$
#

PORTNAME=	paros
PORTVERSION=	3.2.13
PORTREVISION=	1
CATEGORIES=	www security java
MASTER_SITES=	SF/${PORTNAME}/Paros/Version%20${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-unix

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	An HTTP/HTTPS proxy for assessing web application vulnerability

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_JAVA=	yes
JAVA_RUN=	yes
JAVA_VERSION=	1.4+1.5

USE_ZIP=	yes
NO_BUILD=	yes
USE_DOS2UNIX=	release.txt

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|java -jar \(paros.jar\)|cd ${DATADIR} \&\& java -jar ${DATADIR}/\1|g' \
	${WRKSRC}/startserver.sh
	${RM} ${WRKSRC}/startserver.sh.bak

do-install:
	@${MKDIR} ${JAVASHAREDIR}/${PORTNAME}
	(cd ${WRKSRC} && ${COPYTREE_BIN} \* ${JAVASHAREDIR}/${PORTNAME} \
	"! -name startserver.sh")
	${INSTALL_SCRIPT} ${WRKSRC}/startserver.sh ${PREFIX}/bin/paros

.include <bsd.port.mk>
