# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	jarnal
PORTVERSION=	999
CATEGORIES=	textproc editors
MASTER_SITES=	http://levine.sscnet.ucla.edu/general/software/tc1000/
DISTNAME=	${PORTNAME}-install
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A tool to take notes, annotate documents (including PDF), and more

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

LICENSE=	GPLv2

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SCRIPTS=	jarnal.sh jarnalannotate.sh
LIBFILES=	lbouncy_license.html lib-ver.txt jarnal-readme.txt

NO_STAGE=	yes
pre-configure:
	${MV} ${WRKDIR}/lib/readme.txt ${WRKDIR}/lib/jarnal-readme.txt
	${REINPLACE_CMD} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|'	\
		-e 's|%%DATADIR%%|${DATADIR}|' ${SCRIPTS:S|^|${WRKDIR}/|}

do-install:
	${MKDIR} ${JAVAJARDIR}/lib ${DATADIR}/templates
	${INSTALL_DATA} ${PORTNAME:S|^|${WRKDIR}/|:S|$|.jar|} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKDIR}/lib/*.jar ${JAVAJARDIR}/lib/
	${INSTALL_DATA} ${LIBFILES:S|^|${WRKDIR}/lib/|} ${JAVAJARDIR}/lib/
	${INSTALL_SCRIPT} ${SCRIPTS:S|^|${WRKDIR}/|} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/templates/* ${DATADIR}/templates/

.include <bsd.port.mk>
