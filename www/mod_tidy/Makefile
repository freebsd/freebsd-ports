# New ports collection makefile for:	mod_tidy
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_tidy
PORTVERSION=	0.5.5
CATEGORIES=	www
MASTER_SITES=	http://mod-tidy.sourceforge.net/src/ \
		http://keyserver.kjsl.com/~jharris/distfiles/
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Validates the HTML output of your apache2 webserver

LIB_DEPENDS=	tidy:${PORTSDIR}/www/tidy-lib

MAKE_JOBS_SAFE=  yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USE_APACHE=	20+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
AP_INC+=	${LOCALBASE}/include/tidy
AP_LIB+=	${LOCALBASE}/lib -ltidy
PLIST_FILES=	${DOCSDIR:S/${PREFIX}\///}/LICENSE
PLIST_DIRS=	${DOCSDIR:S/${PREFIX}\///}

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../LICENSE ${DOCSDIR}

.include <bsd.port.mk>
