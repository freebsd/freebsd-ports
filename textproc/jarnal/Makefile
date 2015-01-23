# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	jarnal
PORTVERSION=	1078
CATEGORIES=	textproc editors
MASTER_SITES=	http://levine.sscnet.ucla.edu/general/software/tc1000/
DISTNAME=	${PORTNAME}-install
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Tool to take notes, annotate documents (including PDF), and more

LICENSE=	GPLv2

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

SCRIPTS=	jarnal.sh jarnalannotate.sh jarnal-open-file.sh
LIBFILES=	lbouncy_license.html lib-ver.txt jarnal-readme.txt

pre-configure:
	${MV} ${WRKDIR}/lib/readme.txt ${WRKDIR}/lib/jarnal-readme.txt
	${REINPLACE_CMD} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|'	\
		-e 's|%%DATADIR%%|${DATADIR}|' ${SCRIPTS:S|^|${WRKDIR}/|}

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/lib ${STAGEDIR}${DATADIR}/templates
	${INSTALL_DATA} ${PORTNAME:S|^|${WRKDIR}/|:S|$|.jar|} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKDIR}/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/lib/
	${INSTALL_DATA} ${LIBFILES:S|^|${WRKDIR}/lib/|} ${STAGEDIR}${JAVAJARDIR}/lib/
	${INSTALL_SCRIPT} ${SCRIPTS:S|^|${WRKDIR}/|} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/templates/* ${STAGEDIR}${DATADIR}/templates/

.include <bsd.port.mk>
