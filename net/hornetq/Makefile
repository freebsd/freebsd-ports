# New ports collection makefile for:	hornetq
# Date created:		2012-03-16
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	hornetq
PORTVERSION=	2.2.14
CATEGORIES=	net java
MASTER_SITES=	http://downloads.jboss.org/hornetq/
DISTNAME=	${PORTNAME}-${PORTVERSION}.Final

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Multi-protocol asynchronous messaging system

LICENSE=	LGPL21

PORTDOCS=	quickstart-guide api rest-api user-manual \
		rest-interface-manual README.html

USE_RC_SUBR=	hornetq
USE_JAVA=	yes
JAVA_VERSION=	1.6
JAVA_VENDOR=	openjdk

NO_BUILD=	yes
CONFIG_DIRS=	clustered non-clustered
CONFIG_FILES=	hornetq-beans.xml hornetq-users.xml hornetq-configuration.xml \
		jndi.properties hornetq-jms.xml logging.properties

CONFIGURE_WRKSRC=	${WRKSRC}/native-src
LIBTOOLFILES=	native-src/aclocal.m4
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal/
AUTOMAKE_ARGS=	--add-missing -c

post-extract:
	    ${RM} -r ${WRKSRC}/tools ${WRKSRC}/native-src ${WRKSRC}/config/jboss-as*
	    ${RM} ${WRKSRC}/bin/*.bat ${WRKSRC}/bin/*.so ${WRKSRC}/bin/build.sh
	    ${MV} ${WRKSRC}/schemas ${WRKSRC}/config
.for dir in ${CONFIG_DIRS}
.for config in ${CONFIG_FILES}
	    ${MV} ${WRKSRC}/config/stand-alone/${dir}/${config} ${WRKSRC}/config/stand-alone/${dir}/${config}.sample
.endfor
.endfor

do-install:
	    ${MKDIR} ${DATADIR}
	    ${MKDIR} ${DATADIR}/bin
	    ${INSTALL_SCRIPT} ${WRKSRC}/bin/*.sh ${DATADIR}/bin
	    ${MKDIR} ${DOCSDIR}
	    cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
	    cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${DATADIR}
	    ${RM} -f ${WRKSRC}/config/stand-alone/clustered/*.orig
	    ${RM} -f ${WRKSRC}/config/stand-alone/non-clustered/*.orig
	    cd ${WRKSRC} && ${COPYTREE_SHARE} config ${DATADIR}
	    ${MKDIR} ${EXAMPLESDIR}
	    cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}

post-install:
	    PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
