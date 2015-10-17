# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	x10
PORTVERSION=	2.2.1
PORTREVISION=	3
CATEGORIES=	lang devel java
MASTER_SITES=	http://dist.codehaus.org/x10/dependencies/ \
		SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		lpg.runtime.java_2.0.22.jar \
		ecj-3.5.1.jar \
		com.ibm.wala.cast.java_1.0.0.201101071300.jar \
		com.ibm.wala.cast_1.0.0.201101071300.jar \
		com.ibm.wala.core_1.1.3.201101071300.jar \
		com.ibm.wala.shrike_1.3.1.201101071300.jar \
		org.eclipse.equinox.common_3.6.0.v20100503.jar \
		commons-math-2.2.jar \
		bdwgc-7.1.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Object-oriented parallel programming language

LICENSE=	EPL

USES=	tar:bzip2
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
USE_GCC=	yes

USE_LDCONFIG=	${PREFIX}/stdlib/lib

# Can't have USE_GMAKE with USE_ANT: They imply conflicting do-build actions.
BUILD_DEPENDS+=	gmake:${PORTSDIR}/devel/gmake \
		bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/x10.dist

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION:M1.8.*}
BROKEN=		Does not build with JDK 1.8
.endif

post-patch:
	${REINPLACE_CMD} -e 's/value="make"/value="gmake"/g' \
		${WRKDIR}/x10.runtime/build.xml
	${MKDIR} ${WRKSRC}/lib ${WRKDIR}/x10.runtime/src-cpp/bdwgc/src
	${CP} ${DISTDIR}/lpg.runtime.java_2.0.22.jar ${WRKSRC}/lib/lpg.jar
	${CP} ${DISTDIR}/ecj-3.5.1.jar ${WRKSRC}/lib/ecj.jar
	${CP} ${DISTDIR}/com.ibm.wala.cast.java_1.0.0.201101071300.jar ${WRKSRC}/lib
	${CP} ${DISTDIR}/com.ibm.wala.cast_1.0.0.201101071300.jar ${WRKSRC}/lib
	${CP} ${DISTDIR}/com.ibm.wala.core_1.1.3.201101071300.jar ${WRKSRC}/lib
	${CP} ${DISTDIR}/com.ibm.wala.shrike_1.3.1.201101071300.jar ${WRKSRC}/lib
	${CP} ${DISTDIR}/org.eclipse.equinox.common_3.6.0.v20100503.jar ${WRKSRC}/lib
	${CP} ${DISTDIR}/commons-math-2.2.jar ${WRKSRC}/lib
	${CP} ${DISTDIR}/bdwgc-7.1.tar.gz ${WRKDIR}/x10.runtime/src-cpp/bdwgc
	(cd ${WRKDIR}/x10.runtime/src-cpp/bdwgc/src && tar zxvf ../bdwgc-7.1.tar.gz && ${REINPLACE_CMD} -e 's|freebsd1\*|freebsd1.*|g' configure)

do-install:
.for f in X10Launcher apgas precommit x10 x10c x10c++ x10j
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/stdlib
	${INSTALL_DATA} ${WRKSRC}/etc/* ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${PREFIX}/lib
	${CP} -R ${WRKSRC}/stdlib/* ${STAGEDIR}${PREFIX}/stdlib
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
