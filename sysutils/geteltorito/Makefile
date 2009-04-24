# New ports collection makefile for:	geteltorito
# Date created:				Wed Apr 15 11:35:12 PDT 2009
# Whom:					Valerio Daelli <valerio.daelli@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	geteltorito
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.uni-koblenz.de/~krienke/ftp/noarch/geteltorito/
DISTFILES=	${PORTNAME}.pl
EXTRACT_ONLY=

MAINTAINER=	valerio.daelli@gmail.com
COMMENT=	El Torito image extractor

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
