# Created by: Valerio Daelli <valerio.daelli@gmail.com>
# $FreeBSD$

PORTNAME=	geteltorito
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.uni-koblenz.de/~krienke/ftp/noarch/geteltorito/
DISTFILES=	${PORTNAME}.pl
EXTRACT_ONLY=

MAINTAINER=	valerio.daelli@gmail.com
COMMENT=	El Torito image extractor

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
