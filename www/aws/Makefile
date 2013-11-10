# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aws
PORTVERSION=	3.1.0.0
CATEGORIES=	www
MASTER_SITES=	http://downloads.dragonlace.net/src/

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Adacore Ada Web Server and framework

BUILD_DEPENDS=	gprbuild>=20120510:${PORTSDIR}/devel/gprbuild \
		xmlada>=3.2:${PORTSDIR}/textproc/xmlada \
		gnatpython>=20101207:${PORTSDIR}/devel/gnatpython

USE_PYTHON=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
NO_MTREE=	yes
USES=		ada gmake
DOTBUILD=	release
ADDL_RPATH=	${LOCALBASE}/lib:${LOCALBASE}/lib/aws/native/relocatable

OPTIONS_SINGLE=		Secure-Socket-Layer
OPTIONS_DEFINE=		IP6 DEBUG LDAP DSRT RELOC
OPTIONS_DEFAULT=	SSL
NO_OPTIONS_SORT=	yes
OPTIONS_SINGLE_Secure-Socket-Layer= SSL GNUTLS NOSSL

NOSSL_DESC=		Disable SSL support
DSRT_DESC=		Disable shared runtime
RELOC_DESC=		Build shared libraries (default is static)
IP6_DESC=		Support IPv6 instead of IPv4

MAKE_ENV+=	AWK=${AWK}
MAKEFILE=	makefile

CONF_ARGS=	PROCESSORS=${MAKE_JOBS_NUMBER}
CONF_ARGS+=	GCC=ada
CONF_ARGS+=	PYTHON=python${PYTHON_VER}
CONF_ARGS+=	XMLADA=true
CONF_ARGS+=	PRJ_BUILD=${DOTBUILD}
CONF_ARGS+=	prefix=${PREFIX}
CONF_ARGS+=	LPATH=${PREFIX}/lib
CONF_ARGS+=	ZPATH=/usr/lib

.include <bsd.port.options.mk>

###################
##  SSL Support  ##
###################

.if ${PORT_OPTIONS:MSSL}
WITH_OPENSSL_PORT= yes
USE_OPENSSL=	yes
CONF_ARGS+=	SOCKET=openssl
.elif ${PORT_OPTIONS:MGNUTLS}
CONF_ARGS+=	SOCKET=gnutls
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
LIB_DEPENDS+=	crypto:${PORTSDIR}/security/openssl
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
.endif

####################
##  LDAP Support  ##
####################

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONF_ARGS+=	LDAP=true
.endif

####################
##  IPv6 Support  ##
####################

.if ${PORT_OPTIONS:MIP6}
CONF_ARGS+=	IPv6=true
.endif

#####################
##  Debug Support  ##
#####################

.if ${PORT_OPTIONS:MDEBUG}
CONF_ARGS+=	DEBUG=true
.endif

##############################
##  Shared Runtime Library  ##
##############################

.if ${PORT_OPTIONS:MDSRT}
CONF_ARGS+=	ENABLE_SHARED=false
.endif

############################
##  Default Library Type  ##
############################

.if ${PORT_OPTIONS:MRELOC}
CONF_ARGS+=	DEFAULT_LIBRARY_TYPE=relocatable
.endif

post-patch:
	@${REINPLACE_CMD} \
	   -e 's|@ADDITIONAL_RPATH@|${ADDL_RPATH}|' \
	   -e 's|@PREFIX@|${LOCALBASE}|g' \
		${WRKSRC}/src/src.gpr \
		${WRKSRC}/include/include.gpr

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${GMAKE} setup ${CONF_ARGS}

do-build:
#	We cannot use a redefined ALL_TARGET because MAKE_JOBS_SAFE is set
#	for PROCESSORS, but that also sets -j for gmake which breaks build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_ARGS} build build_doc

test: install
	@cd ${WRKSRC}/regtests && ${SETENV} ${MAKE_ENV} \
		python${PYTHON_VER} testsuite.py

post-install:
# 	AWS plist changes due to options are complex, and are not simply
#	additive.  Trying to capture every permutation is error prone and
#	tedious, so a generated PLIST is the way to go.
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} > ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | ${SORT} -r | \
	   ${SED} -e '/lib\/gnat$$/d' -e '/share\/doc$$/d' -e '/share\/gps/d' \
	   -e '/share\/examples$$/d' -e 's/^/@dirrm /g' >> ${TMPPLIST}
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gps/plug-ins 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gps 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/doc 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/examples 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
