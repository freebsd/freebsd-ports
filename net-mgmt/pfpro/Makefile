# Ports collection makefile for:    Castor
# Date created:         2005/05/12
# Whom:                 Adam VanderHook <acidos@bandwidth-junkies.net>
#
# $FreeBSD$
#

PORTNAME=	pfpro
PORTVERSION=	0.1.1
CATEGORIES=	net-mgmt java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pfpro
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	acidos@bandwidth-junkies.net
COMMENT=	Cross-platform GUI fat client for PF

BUILD_DEPENDS=	${JAVALIBDIR}/castor.jar:${PORTSDIR}/java/castor \
		${JAVALIBDIR}/jakarta-oro.jar:${PORTSDIR}/java/jakarta-oro \
		${JAVALIBDIR}/xalan.jar:${PORTSDIR}/textproc/xalan-j

USE_JAVA=	yes
JAVA_VERSION=	1.4
USE_ANT=	yes
USE_JIKES=	no
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES

WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}

XMLDIR=		${PREFIX}/share/xml/${PORTNAME}
XML_FILES=	firewall.xsd

XSLDIR=		${PREFIX}/share/xsl/${PORTNAME}
XSL_FILES=	xml2pf.xsl 001to010.xsl

JARFILE=	${PORTNAME}.jar

DOCS=		BUGS CHANGELOG HACKING README RELNOTES
EXAMPLES=	baseline.xml workstation.xml

SUB_FILES=	pfpro.sh pkg-message
SUB_LIST=	XSLDIR=${XSLDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	@${RM} -rf ${WRKSRC}/dist

do-install:
	${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}

	@${MKDIR} ${XMLDIR}
	cd ${WRKSRC}/xml && ${INSTALL_DATA} ${XML_FILES} ${XMLDIR}
	@${MKDIR} ${XSLDIR}
	cd ${WRKSRC}/xsl && ${INSTALL_DATA} ${XSL_FILES} ${XSLDIR}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/xml && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}

	${INSTALL_SCRIPT} ${WRKDIR}/pfpro.sh ${PREFIX}/bin/pfpro

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
