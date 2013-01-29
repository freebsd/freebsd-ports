# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	hornetq
DISTVERSION=	2.2.24.GA
PORTREVISION=	0
CATEGORIES=	net java
#MASTER_SITES=	http://downloads.jboss.org/hornetq/
#DISTNAME=	${PORTNAME}-${PORTVERSION}.Final

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Multi-protocol asynchronous messaging system

LICENSE=	LGPL21

BUILD_DEPENDS=	${MAVEN3}:${PORTSDIR}/devel/maven3 \
		ant:${PORTSDIR}/devel/apache-ant

PORTDOCS=	quickstart-guide api rest-api user-manual \
		rest-interface-manual README.html

USE_RC_SUBR=	hornetq

USE_GITHUB=	yes
GH_ACCOUNT=	hornetq
GH_TAGNAME=	HornetQ_2_2_24_EAP_GA
GH_COMMIT=	4ed82d3

USE_JAVA=	yes
JAVA_VERSION=	1.7
JAVA_VENDOR=	openjdk
MAVEN3=		${LOCALBASE}/share/java/maven3/bin/mvn
CONFIG_DIRS=	clustered non-clustered
CONFIG_FILES=	hornetq-beans.xml hornetq-users.xml hornetq-configuration.xml \
		jndi.properties hornetq-jms.xml logging.properties

CONFIGURE_WRKSRC=	${WRKSRC}/native-src
LIBTOOLFILES=	native-src/aclocal.m4
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal/
AUTOMAKE_ARGS=	--add-missing -c

do-build:
		cd ${WRKSRC} && ./build.sh bin-distro
		${MV} ${WRKSRC}//build/hornetq-${DISTVERSION}.tar.gz ${WRKDIR}
		${RM} -r ${WRKSRC}
		cd ${WRKDIR} && tar xzvf hornetq-${DISTVERSION}.tar.gz && \
		${MV} hornetq-${DISTVERSION} ${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}

post-build:
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
