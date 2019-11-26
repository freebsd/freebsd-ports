# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	jarnal
PORTVERSION=	1079
CATEGORIES=	textproc editors
MASTER_SITES=	http://www.dklevine.com/general/software/tc1000/
DISTNAME=	${PORTNAME}-install
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Tool to take notes, annotate documents (including PDF), and more

LICENSE=	GPLv2

USES=		zip
USE_JAVA=	yes

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

SCRIPTS=	jarnal.sh jarnalannotate.sh jarnal-open-file.sh
LIBFILES=	lbouncy_license.html lib-ver.txt jarnal-readme.txt

pre-configure:
	${MV} ${WRKSRC}/lib/readme.txt ${WRKSRC}/lib/jarnal-readme.txt
	${REINPLACE_CMD} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|'	\
		-e 's|%%DATADIR%%|${DATADIR}|' ${SCRIPTS:S|^|${WRKSRC}/|}

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/lib ${STAGEDIR}${DATADIR}/templates
	${INSTALL_DATA} ${PORTNAME:S|^|${WRKSRC}/|:S|$|.jar|} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/lib/
	${INSTALL_DATA} ${LIBFILES:S|^|${WRKSRC}/lib/|} ${STAGEDIR}${JAVAJARDIR}/lib/
	${INSTALL_SCRIPT} ${SCRIPTS:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/templates/* ${STAGEDIR}${DATADIR}/templates/

.include <bsd.port.mk>
