# New ports collection makefile for:    postfixadmin
# Date created:                         23 October 2003
# Whom:                                 Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	postfixadmin
PORTVERSION=	1.5.4
CATEGORIES=	mail
MASTER_SITES=	http://high5.net/postfixadmin/download.php/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rob@debank.tv
COMMENT=	PHP frontend to postfix and mySQL

.if defined(WITH_APACHE2)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache2/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.endif

NO_BUILD=	yes
FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

do-fetch:
		${FETCH_CMD} ${FETCH_BEFORE_ARGS} \
		${MASTER_SITES}?file=${DISTNAME}${EXTRACT_SUFX}

post-patch:
		${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
		@${MKDIR} ${PREFIX}/www/postfixadmin
		@${CP} -r ${WRKSRC}/* ${PREFIX}/www/postfixadmin/

.include <bsd.port.mk>
