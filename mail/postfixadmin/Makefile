# New ports collection makefile for:    postfixadmin
# Date created:                         23 October 2003
# Whom:                                 Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	postfixadmin
PORTVERSION=	2.0.2
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
		@${MKDIR} ${PREFIX}/www/postfixadmin/VIRTUAL_VACATION
		@${MKDIR} ${PREFIX}/www/postfixadmin/admin
		@${MKDIR} ${PREFIX}/www/postfixadmin/languages
		@${MKDIR} ${PREFIX}/www/postfixadmin/templates
		@${MKDIR} ${PREFIX}/www/postfixadmin/users
		@${INSTALL_DATA} ${WRKSRC}/*.TXT ${PREFIX}/www/postfixadmin
		@${INSTALL_DATA} ${WRKSRC}/*.php ${PREFIX}/www/postfixadmin
		@${INSTALL_DATA} ${WRKSRC}/*.png ${PREFIX}/www/postfixadmin
		@${INSTALL_DATA} ${WRKSRC}/*.sample ${PREFIX}/www/postfixadmin
		@${INSTALL_DATA} ${WRKSRC}/*.css ${PREFIX}/www/postfixadmin
		@${INSTALL_DATA} ${WRKSRC}/VIRTUAL_VACATION/* ${PREFIX}/www/postfixadmin/VIRTUAL_VACATION
		@${INSTALL_DATA} ${WRKSRC}/admin/* ${PREFIX}/www/postfixadmin/admin
		@${INSTALL_DATA} ${WRKSRC}/admin/.ht* ${PREFIX}/www/postfixadmin/admin
		@${INSTALL_DATA} ${WRKSRC}/languages/* ${PREFIX}/www/postfixadmin/languages
		@${INSTALL_DATA} ${WRKSRC}/templates/* ${PREFIX}/www/postfixadmin/templates
		@${INSTALL_DATA} ${WRKSRC}/users/* ${PREFIX}/www/postfixadmin/users

.include <bsd.port.mk>
