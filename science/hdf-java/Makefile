# Created by: rfarmer@predatorlabs.net
# $FreeBSD$

PORTNAME=	hdf-java
PORTVERSION=	2.10
CATEGORIES=	science java
MASTER_SITES=	http://www.hdfgroup.org/ftp/HDF5/releases/HDF-JAVA/hdf-java-${PORTVERSION}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java interface to HDF5

LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5-18 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_BUILD=	yes
JAVA_RUN=	yes

USES=		dos2unix gmake
DOS2UNIX_REGEX=	.*/examples/.*Makefile.in

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=${STAGEDIR}${PREFIX}
GNU_CONFIGURE_MANPREFIX=${STAGEDIR}${PREFIX}
CONFIGURE_ARGS=	--with-jdk=${JAVA_HOME}/include,${JAVA_HOME}/jre/lib/ \
		--with-hdf5=${LOCALBASE}/include \
		--with-libz=/lib \
		--with-libjpeg=${LOCALBASE} \
		--without-hdf4 \
		--without-h4toh5
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	SZIP DOCS
SZIP_DESC=	SZIP support (must match with science/hdf5-18)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSZIP}
CONFIGURE_ARGS+=	--with-libsz=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--without-libsz
.endif

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET=	all javadocs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"/libhdf.$$LLEXT"|"${LOCALBASE}/lib"|' \
		-e 's|$$z_lib"/libz."$$LLEXT|"/lib/libz.so.*"|' \
		-e 's|$$sz_lib"/libsz."$$LLEXT|"${LOCALBASE}/lib/libsz.so.*"|' \
		-e 's|LLEXT="a"|LLEXT="so"|g' \
		-e 's|COPT="-shared"|COPT="-fPIC"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(JH45INSTALLDIR)/lib|${STAGEDIR}${JAVAJARDIR}|g' \
		-e 's|INSTALL_LIB |${INSTALL_LIB} |' \
		-e 's|cp |${INSTALL_DATA} |g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|$$HDFJAVA"/lib/freebsd:"$$HDFJAVA"/lib/ext|${PREFIX}/lib"|' \
		-e 's|$$HDFJAVA"/lib|${JAVAJARDIR}"|g' \
		${WRKSRC}/bin/hdfview.sh.in

post-build:
	@${REINPLACE_CMD} -e 's|${STAGEDIR}||' ${WRKSRC}/bin/hdfview.sh

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/UsersGuide
	(cd ${WRKSRC}/docs/hdfview/ && ${COPYTREE_SHARE} "UsersGuide" \
	    ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} "javadocs" \
	    ${STAGEDIR}${DOCSDIR}/)
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} check

.include <bsd.port.mk>
