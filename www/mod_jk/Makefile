# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_jk
PORTVERSION=	1.2.41
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	APACHE/tomcat/tomcat-connectors/jk/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	tomcat-connectors-${PORTVERSION}-src

MAINTAINER?=	girgen@FreeBSD.org
COMMENT?=	Apache JK module for connecting to Tomcat using AJP1X

USES=		apache:2.2+ gmake
APACHE_VER=	2.0
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-apxs=${APXS}
WRKSRC=		${WRKDIR}/tomcat-connectors-${PORTVERSION}-src/native

SUB_FILES=	mod_jk.conf.sample pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${APXS} -i -n jk -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} ${WRKSRC}/apache-${APACHE_VER}/mod_jk.so
	${MKDIR} ${STAGEDIR}${LOCALBASE}/${APACHEETCDIR}
	${INSTALL_DATA} ${WRKDIR}/mod_jk.conf.sample ${STAGEDIR}${LOCALBASE}/${APACHEETCDIR}
	${INSTALL_DATA} ${FILESDIR}/workers.properties.sample ${STAGEDIR}${LOCALBASE}/${APACHEETCDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_jk.so

.include <bsd.port.mk>
