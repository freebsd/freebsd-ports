# New ports collection makefile for:	mod_tidy
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_tidy
PORTVERSION=	0.3
CATEGORIES=	www
MASTER_SITES=	http://home.snafu.de/tusk/mod_tidy/
DIST_SUBDIR=	apache

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Validates the HTML output of your apache2 webserver

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	tidy:${PORTSDIR}/www/tidy-lib

RESTRICTED=	"no license"

APXS?=		${LOCALBASE}/sbin/apxs

TIDY_INC=	${LOCALBASE}/include/tidy
TIDY_LIBS=	${LOCALBASE}/lib

post-extract:
	@${ECHO_MSG} "===>  Removing distributed tidy libs to avoid conflicts"
	@${RM} -fr ${WRKSRC}/tidy

do-build:
	@(cd ${WRKSRC}/src && ${APXS} -I ${TIDY_INC} -L ${TIDY_LIBS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC}/src && ${APXS} -A -i ${PORTNAME}.la)

.include <bsd.port.mk>
