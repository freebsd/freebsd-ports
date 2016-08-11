# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws
PORTVERSION=	17.0.0
CATEGORIES=	www

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Adacore Ada Web Server and framework

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	gprbuild:devel/gprbuild \
		templates_parser>11:textproc/templates_parser \
		xmlada>=4.4:textproc/xmlada \
		asis>=2013:lang/asis \
		gnatpython>=20101207:devel/gnatpython
RUN_DEPENDS=	templates_parser>11:textproc/templates_parser \
		xmlada>=4.4:textproc/xmlada

USES=		ada:run gmake python shebangfix tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_PROJECT=	aws
GH_TAGNAME=	31d491e

GNU_CONFIGURE=	yes
NO_MTREE=	yes
DOTBUILD=	release
LINK_SSL=	--
LINK_TLS=	--
LINK_LDP=	--
NAME_IP6=	--
NAME_STD=	--
BUILD_TYPE=	release
ADDL_RPATH=	${LOCALBASE}/lib:${LOCALBASE}/lib/aws/native/relocatable
AUX_TARGET=	${ARCH:S/amd64/x86_64/}-aux-${OPSYS:tl}${OSREL}
TEMPARSE=	${WRKSRC}/.build/${AUX_TARGET}/${BUILD_TYPE}
SHEBANG_FILES=	tools/awsascb

OPTIONS_SINGLE=		Secure-Socket-Layer
OPTIONS_DEFINE=		IP6 DEBUG LDAP SHARED DOCS
OPTIONS_DEFAULT=	SSL SHARED
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
OPTIONS_SINGLE_Secure-Socket-Layer= SSL GNUTLS

SHARED_DESC=		Build shared libraries in addition to static ones
IP6_DESC=		Support IPv6 instead of IPv4

CONF_ARGS=	PROCESSORS=${MAKE_JOBS_NUMBER}
CONF_ARGS+=	GCC=ada
CONF_ARGS+=	PYTHON=python${PYTHON_VER}
CONF_ARGS+=	XMLADA=true
CONF_ARGS+=	PRJ_BUILD=${DOTBUILD}
CONF_ARGS+=	prefix=${PREFIX}
CONF_ARGS+=	LPATH=${PREFIX}/lib
CONF_ARGS+=	ZPATH=/usr/lib
CONF_ARGS+=	ZLIB=true
CONF_ARGS+=	ASIS=true
CONF_ARGS+=	DEFAULT_LIBRARY_TYPE=static

.include <bsd.port.options.mk>

###################
##  SSL Support  ##
###################

.if ${PORT_OPTIONS:MSSL}
WITH_OPENSSL_PORT= yes
USE_OPENSSL=	yes
CONF_ARGS+=	SOCKET=openssl
CONF_ARGS+=	LPATH=${PREFIX}/lib
LINK_SSL=
.endif
.if ${PORT_OPTIONS:MGNUTLS}
CONF_ARGS+=	SOCKET=gnutls
LIB_DEPENDS+=	libgnutls.so:security/gnutls
LINK_TLS=
.endif

####################
##  LDAP Support  ##
####################

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONF_ARGS+=	LDAP=true
LINK_LDP=
.endif

####################
##  IPv6 Support  ##
####################

.if ${PORT_OPTIONS:MIP6}
CONF_ARGS+=	IPv6=true
NAME_IP4=	--
NAME_IP6=
.endif

#####################
##  Debug Support  ##
#####################

.if ${PORT_OPTIONS:MDEBUG}
CONF_ARGS+=	DEBUG=true
BUILD_TYPE=	debug
.endif

##############################
##  Shared Runtime Library  ##
##############################

.if ${PORT_OPTIONS:MSHARED}
CONF_ARGS+=	ENABLE_SHARED=true
.else
CONF_ARGS+=	ENABLE_SHARED=false
.endif

post-patch:
	@${MKDIR} ${WRKSRC}/templates_parser \
		${TEMPARSE}/static/obj/temparse \
		${TEMPARSE}/static/lib/temparse \
		${TEMPARSE}/relocatable/obj/temparse \
		${TEMPARSE}/relocatable/lib/temparse \
		${WRKSRC}/templates_parser/tools \
		${WRKSRC}/templates_parser/xsrc \
		${WRKSRC}/templates_parser/src
	@${REINPLACE_CMD} \
	    -e 's|@ADDITIONAL_RPATH@|${ADDL_RPATH}|' \
	    -e 's|@PREFIX@|${LOCALBASE}|g' \
		${WRKSRC}/aws.gpr \
		${WRKSRC}/src/src.gpr \
		${WRKSRC}/include/include.gpr
	@${SED} -e 's|@PREFIX@|${LOCALBASE}|g' ${FILESDIR}/temparse.gpr.in \
		> ${WRKSRC}/templates_parser/temparse.gpr

do-configure:
#	If we want to do templates_parser copy in an earlier target then
#	templates_parser needs to be listed as an EXTRACT_DEPENDS
	@${CP} ${LOCALBASE}/lib/templates_parser/* \
		${TEMPARSE}/static/lib/temparse
	@${CP} ${LOCALBASE}/lib/templates_parser.relocatable/*.ali \
		${TEMPARSE}/relocatable/lib/temparse
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${MAKE_CMD} setup ${CONF_ARGS}

do-build:
#	We cannot use a redefined ALL_TARGET because MAKE_JOBS_SAFE is set
#	for PROCESSORS, but that also sets -j for gmake which breaks build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} build
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} html
.endif

test:
.if exists(${LOCALBASE}/bin/awsres)
	@cd ${WRKSRC}/regtests && ${SETENV} ${MAKE_ENV} TIMEOUT=75 \
		python${PYTHON_VER} testsuite.py
.else
	@${ECHO} "AWS has to be installed before testing"
.endif

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/gpr/manifests
	${RM} ${STAGEDIR}${PREFIX}/include/aws.relocatable/Makefile
	${RM} ${STAGEDIR}${PREFIX}/include/aws/Makefile
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/share/gps/plug-ins
	${CAT} ${FILESDIR}/aws.gpr.in | ${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		-e 's|@SSL@|${LINK_SSL}|g' -e 's|@TLS@|${LINK_TLS}|g' \
		-e 's|@LDP@|${LINK_LDP}|g' -e 's|@IP4@|${NAME_IP4}|g' \
		-e 's|@IP6@|${NAME_IP6}|g' -e 's|@STD@|${NAME_STD}|g' \
		> ${STAGEDIR}${PREFIX}/lib/gnat/aws.gpr
	cd ${WRKSRC}/gps && ${INSTALL_DATA} *.xml aws.py \
		${STAGEDIR}${PREFIX}/share/gps/plug-ins

.include <bsd.port.mk>
