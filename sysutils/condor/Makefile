# Created by: Andy Pavlo
# $FreeBSD$

PORTNAME=	condor
PORTVERSION=	8.0.3
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.acadix.biz/Ports/distfiles/
DISTNAME=	condor_src-${PORTVERSION}-all-all

MAINTAINER=	jwbacon@tds.net
COMMENT=	High-throughput computing on distributively owned resources

LICENSE=	APACHE20

LIB_DEPENDS+=	libkrb5support.so:${PORTSDIR}/security/krb5 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libcurl.so:${PORTSDIR}/ftp/curl

WRKSRC=		${WRKDIR}/condor-${PORTVERSION}
USE_LDCONFIG=	yes
USES=		cmake gmake perl5
USE_GCC=	any
USE_PGSQL=	server
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-rpath=${LOCALBASE}/lib:/usr/lib:/lib
CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS:STRING=${CXXFLAGS} \
		-DCMAKE_EXE_LINKER_FLAGS:STRING=${LDFLAGS}

SUB_FILES=	condor_config condor_config.local pkg-message

USERS=		condor
GROUPS=		${USERS}

USE_RC_SUBR=	condor

PORTEXAMPLES=	*
PORTDOCS=	*

.include <bsd.port.pre.mk>

pre-everything::
	@( ${PRINTF} "\nWARNING: Condor needs approximately 3GB to build!"; \
	   ${PRINTF} "         Please make sure your build environment has that much before continuing.\n" )

post-patch:
	@${REINPLACE_CMD} \
		-e 's,\(set( C_SHARE_EXAMPLES	\)share/condor,\1${EXAMPLESDIR_REL},' \
		${WRKSRC}/build/cmake/CondorPackageConfig.cmake
	@${REINPLACE_CMD} \
		-e '/create_symlink/d' ${WRKSRC}/src/condor_scripts/CMakeLists.txt

post-install:
	${INSTALL_DATA} ${WRKDIR}/condor_config ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/condor_config.local ${STAGEDIR}${ETCDIR}
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if defined(NOPORTEXAMPLES)
	${RM} -rf ${STAGEDIR}${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
