# New ports collection makefile for:	hdf-java
# Date created:				11 February 2010
# Whom:					rfarmer@predatorlabs.net
#
# $FreeBSD$
#

PORTNAME=	hdf-java
PORTVERSION=	2.6.1
CATEGORIES=	science java
MASTER_SITES=	http://www.hdfgroup.org/ftp/HDF5/hdf-java/src/ \
		http://www.predatorlabs.net/dl/
EXTRACT_SUFX=	-src.tar

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Java interface to HDF5

LIB_DEPENDS=	hdf5.6:${PORTSDIR}/science/hdf5-18

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_BUILD=	yes
JAVA_RUN=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jdk=${JAVA_HOME}/include,${JAVA_HOME}/jre/lib/ \
		--with-hdf5=${LOCALBASE}/include \
		--with-libz=/lib

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|"/libhdf.$$LLEXT"|"${LOCALBASE}/lib"|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|$$z_lib"/libz."$$LLEXT|"/lib/libz.so.*"|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|LLEXT="a"|LLEXT="so"|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|COPT="-shared"|COPT="-fPIC"|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|$$(JH45INSTALLDIR)/lib|${JAVAJARDIR}|' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|$$(LIBDIR)/@JAVATARG@|${PREFIX}/lib|g' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|cp -R|#|' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|cp ./lib/@JAVATARG@|${INSTALL_PROGRAM} ./lib/@JAVATARG@|g' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|cp |${INSTALL_DATA} |g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/UsersGuide
	(cd ${WRKSRC}/docs/hdfview/ && ${COPYTREE_SHARE} "UsersGuide" ${DOCSDIR}/)
.endif

.include <bsd.port.mk>
