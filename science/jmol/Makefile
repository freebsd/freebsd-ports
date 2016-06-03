# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	jmol
PORTVERSION=	13.2.3
CATEGORIES=	science java
MASTER_SITES=	SF/${PORTNAME}/Jmol/Version%2013.2/Version%20${PORTVERSION}:source1 \
		http://jmol.svn.sourceforge.net/viewvc/jmol/trunk/Jmol/selfSignedCertificate/:source2
DISTFILES=	Jmol-${PORTVERSION}-full.tar.gz:source1 \
		selfSignedCertificate.cer:source2 \
		selfSignedCertificate.store:source2
EXTRACT_ONLY=	Jmol-${PORTVERSION}-full.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source Java viewer for chemical structures in 3D

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USE_JAVA=	yes
JAVA_VERSION=	1.7+
USE_ANT=	yes
ALL_TARGET=	all

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SIGN_DIR=	${WRKSRC}/selfSignedCertificate
SUB_FILES=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Jmol" "" "" "${PORTNAME}" "" false

post-extract:
	@${MKDIR} ${SIGN_DIR}
	@${CP} ${DISTDIR}/selfSignedCertificate.cer ${SIGN_DIR}
	@${CP} ${DISTDIR}/selfSignedCertificate.store ${SIGN_DIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/build && ${INSTALL_DATA} Jmol.jar JmolData.jar \
		JmolLib.jar ${STAGEDIR}${JAVAJARDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
.undef MAKE_ARGS
