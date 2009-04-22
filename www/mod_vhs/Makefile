# New ports collection makefile for:	mod_vhs
# Date created:				Sun Jul 25 2004
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	mod_vhs
PORTVERSION=	1.0.32
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.oav.net/projects/${PORTNAME}/
DIST_SUBDIR=	apache2

MAINTAINER=	kiwi@oav.net
COMMENT=	Allows mass virtual hosting using libhome system with Apache 2.0.x

LIB_DEPENDS+=	home:${PORTSDIR}/misc/libhome

USE_APACHE=	2.0
USE_PHP=	yes
USE_PHP_BUILD=	yes
WANT_PHP_MOD=	yes
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

AP_INC+=	${LOCALBASE}/include/home \
		   	-I ${LOCALBASE}/include/php \
			-I ${LOCALBASE}/include/php/Zend \
			-I ${LOCALBASE}/include/php/TSRM \
			-I ${LOCALBASE}/include/php/main
AP_LIB+=	${LOCALBASE}/lib -lhome
AP_EXTRAS+=	-DHAVE_MOD_PHP_SUPPORT

PORTDOCS=	ChangeLog AUTHORS README.logs README.wildcards WARNING \
		README.phpopt

post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

# TODO :
#   Add suphp support

.include <bsd.port.mk>
