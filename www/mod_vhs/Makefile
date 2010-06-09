# New ports collection makefile for:	mod_vhs
# Date created:				Sun Jul 25 2004
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	mod_vhs
PORTVERSION=	1.0.32
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.oav.net/openvisp/${PORTNAME}/
DIST_SUBDIR=	apache2

MAINTAINER=	kiwi@oav.net
COMMENT=	Allows mass virtual hosting using libhome system with Apache 2.0.x

LIB_DEPENDS+=	home:${PORTSDIR}/misc/libhome

MANUAL_PACKAGE_BUILD=	lang/php5 is built with www/apache13 by default which conflicts

USE_APACHE=	2.0+
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
