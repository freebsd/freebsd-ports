# New ports collection makefile for:	twig
# Date created:				12 Jun 2002
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	twig
PORTVERSION=	2.7.6
CATEGORIES=	www mail
MASTER_SITES=	http://twig.screwdriver.net/download/

MAINTAINER=	dinoex@FreeBSD.org

.if !defined(WITH_PHP3)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3
.endif
.if !defined(WITH_MYSQL)
LIB_DEPENDS=	pq.2:${PORTSDIR}/databases/postgresql7
.else
.endif

NO_BUILD=	YES
TWIG?=		www/data.default/twig
PLIST_SUB+=	TWIG=${TWIG}

do-install:
	-${MKDIR} ${PREFIX}/${TWIG}/
	(cd ${WRKSRC} && ./twig-install ${PREFIX}/${TWIG} )

.include <bsd.port.mk>
