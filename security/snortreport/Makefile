# Created by: Andrea Venturoli <freebsd@netfence.it>
# $FreeBSD$

PORTNAME=	snortreport
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://www.symmetrixtech.com/ids/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Add-on module for snort to generate real-time web reports

LICENSE=	GPLv2

.if !defined(WITHOUT_JPGRAPH)
RUN_DEPENDS=	${LOCALBASE}/share/jpgraph/jpgraph.php:${PORTSDIR}/graphics/jpgraph2
.endif

USE_PHP=	yes
WANT_PHP_WEB=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
NO_BUILD=	yes

NO_STAGE=	yes
pre-everything::
	@${ECHO} ""
	@${ECHO} "You have to configure PHP either with MySQL or PostgreSQL"
	@${ECHO} "support in order to let snortreport collect its data."
	@${ECHO} "Is is also suggested to compile support for GD in"
	@${ECHO} "and have Jpgraph installed in order to view the charts."
	@${ECHO} ""

pre-patch:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' \
		${PKGDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	${MKDIR} ${PREFIX}/www/snortreport
	${CP} -p ${WRKSRC}/*.php ${PREFIX}/www/snortreport
	${CP} -p ${WRKSRC}/*.css ${PREFIX}/www/snortreport
	${CP} -p ${WRKSRC}/*.png ${PREFIX}/www/snortreport
	${CP} -p ${WRKSRC}/*.html ${PREFIX}/www/snortreport
	${CP} -p ${WRKSRC}/*.phps ${PREFIX}/www/snortreport
	${CP} -p ${WRKSRC}/*.js ${PREFIX}/www/snortreport
	${CHOWN} -R www:www ${PREFIX}/www/snortreport

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Performance.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/create_indexes.sql ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
