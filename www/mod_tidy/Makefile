# New ports collection makefile for:	mod_tidy
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_tidy
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/
DIST_SUBDIR=	apache

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Validates the HTML output of your apache2 webserver

LIB_DEPENDS=	tidy:${PORTSDIR}/www/tidy-lib

RESTRICTED=	"no license"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
WANT_APACHE=	2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
AP_INC+=	${LOCALBASE}/include/tidy
AP_LIB+=	${LOCALBASE}/lib -ltidy

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"
.include <bsd.port.post.mk>
