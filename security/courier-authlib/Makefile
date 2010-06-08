# New ports collection makefile for:	courier-authlib
# Date created:				19 Dec 2004
# Whom:					Oliver Lehmann
#
# $FreeBSD$
#

PORTNAME=	courier-authlib
PORTVERSION=	0.63.0
PORTREVISION=	1
CATEGORIES?=	security mail
.if defined(PKGNAMESUFFIX)
MASTER_SITES=	SF/courier/authlib/${PORTVERSION}
MASTER_SITE_SUBDIR=	courier
.else
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty
.endif

MAINTAINER=	oliver@FreeBSD.org
COMMENT?=	Meta-port for the courier authentication library

CONFLICTS=	courier-0.45*

.if !defined(PKGNAMESUFFIX)
RUN_DEPENDS=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base

NO_BUILD=	yes
PATCHDIR=	/dev/null

OPTIONS+=	GDBM	"Use gdbm instead of system bdb"	off

.include "${.CURDIR}/Makefile.opt"

.else	# !defined(PKGNAMESUFFIX)

USE_AUTOTOOLS=	libltdl:22
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_SUBMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

MAILOWN=	courier
MAILGRP=	courier
MAILUID=	465
MAILGID=	465
LOCALSTATEDIR=	/var
AUTHDAEMONVAR=	${LOCALSTATEDIR}/run/authdaemond

VPOPMAILDIR?=	${LOCALBASE}/vpopmail
USERDB?=	${PREFIX}/etc/userdb

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS='${CPPFLAGS}' \
		LDFLAGS='${LDFLAGS}'
MAKE_ENV:=	${CONFIGURE_ENV}

CONFIGURE_ARGS=	--enable-unicode \
		--enable-ltdl-install=no \
		--without-authcustom \
		--without-authshadow \
		--without-authpwd \
		--with-mailuser=${MAILOWN} \
		--with-mailgroup=${MAILGRP} \
		--localstatedir=${LOCALSTATEDIR} \
		--with-authdaemonvar=${AUTHDAEMONVAR} \
		--cache-file=${WRKDIR}/courier-authlib.cache

INSTALL_TARGET=	install-strip install-configure

DESCR=		${PKGDIR}/pkg-descr${PKGNAMESUFFIX}
PLIST=		${PKGDIR}/pkg-plist${PKGNAMESUFFIX:S/gdbm/db/}

AUTHMOD=	auth${PKGNAMESUFFIX:S/-//:S/gdbm/db/}

.if ${AUTHMOD} == authbase
RUN_DEPENDS+=	${LOCALBASE}/share/sysconftool/sysconftool:${PORTSDIR}/devel/sysconftool
CONFIGURE_ARGS+=--with-base --with-authpam

MAN1=		courierlogger.1 authtest.1

MAN3=		authlib.3 auth_generic.3 auth_login.3 auth_getuserinfo.3 \
		auth_enumerate.3 auth_passwd.3 auth_getoption.3 auth_sasl.3 \
		auth_sasl_ex.3

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README \
		README.authdebug.html README_authlib.html

PLIST_SUB+=	MAILOWN=${MAILOWN} MAILGRP=${MAILGRP} \
		MAILUID=${MAILUID} MAILGID=${MAILGID} \
		AUTHDAEMONVAR=${AUTHDAEMONVAR}
SUB_LIST:=	${PLIST_SUB}
SUB_FILES+=	pkg-install pkg-deinstall

.if defined(WITH_AUTHPIPE_PROG)
CONFIGURE_ARGS+=--with-pipeprog=${WITH_AUTHPIPE_PROG}
.endif

.else
RUN_DEPENDS+=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base
CONFIGURE_ARGS+=--without-base --without-authpam
REMOVE_SUBDIRS+=liblock liblog
.endif

.if ${AUTHMOD} == authuserdb
MAN8=		makeuserdb.8 userdb.8 userdbpw.8
.if ${PKGNAMESUFFIX} == -usergdbm
CONFLICTS+=	${PORTNAME}-userdb-0.*
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=--with-db=gdbm
.elif ${PKGNAMESUFFIX} == -userdb
CONFLICTS+=	${PORTNAME}-usergdbm-0.*
CONFIGURE_ARGS+=--with-db=db
.endif
CONFIGURE_ARGS+=--with-userdb=${USERDB}
.else
CONFIGURE_ARGS+=--with-db=db --without-authuserdb
REMOVE_SUBDIRS+=makedat userdb
.endif

.if ${AUTHMOD} == authldap
DOCS=		README.ldap
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-authldap
.else
CONFIGURE_ARGS+=--without-authldap
.endif

.if ${AUTHMOD} == authmysql
DOCS=		README.authmysql.html README.authmysql.myownquery
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-authmysql \
		--with-mysql-libs=${LOCALBASE}/lib/mysql \
		--with-mysql-includes=${LOCALBASE}/include/mysql
.else
CONFIGURE_ARGS+=--without-authmysql
.endif

.if ${AUTHMOD} == authpgsql
DOCS=		README.authpostgres.html
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-authpgsql
.else
CONFIGURE_ARGS+=--without-authpgsql
.endif

.if ${AUTHMOD} == authvchkpw
BUILD_DEPENDS+=	${VPOPMAILDIR}/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
CONFIGURE_ARGS+=--with-authvchkpw
.else
CONFIGURE_ARGS+=--without-authvchkpw
.endif

.endif	# !defined(PKGNAMESUFFIX)

.include <bsd.port.pre.mk>

.if !defined(PKGNAMESUFFIX)

.include "${.CURDIR}/Makefile.dep"

do-install:	#empty
do-build:	#empty
.else	# !defined(PKGNAMESUFFIX)

.if ${AUTHMOD} == authbase
.if defined(WITH_RCORDER)
USE_RCORDER=	courier-authdaemond.sh
.else
USE_RC_SUBR=	courier-authdaemond.sh
.endif

pre-everything::
	@${ECHO_CMD}
	@${ECHO_CMD}	"	Set WITH_AUTHPIPE_PROG to a program you want to use instead of"
	@${ECHO_CMD}	"	authProg for libauthpipe"
	@${ECHO_CMD}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$VPOPMAILLIBS|& -lcrypt|g;  \
		s|^\(INSTALL_STRIP_PROGRAM=\).*$$|\1"$${INSTALL_PROGRAM} -s"| ; \
		s|mysql_connect|mysql_real_connect|g' \
		${WRKSRC}/*/configure \
		${WRKSRC}/configure
.for subdir in ${REMOVE_SUBDIRS}
	@${REINPLACE_CMD} -E 's,(^(ac_subdirs_all|subdirs).*)${subdir},\1,g' \
		${WRKSRC}/configure
.endfor
	@${REINPLACE_CMD} -e 's|$$(INSTALL_DATA) \(.$$$$file.\)|${INSTALL_MAN} \1|' \
		${WRKSRC}/*/Makefile.in \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^\(DEFAULTOPTIONS=\)""$$|\1"wbnodsn=1"|' \
		-e 's|@ALLMODULES@|authuserdb authvchkpw authpam authldap authmysql authpgsql|' \
		${WRKSRC}/authdaemonrc.in
	@${REINPLACE_CMD} -e 's:@EXPECT@:${SETENV} expect:' \
		${WRKSRC}/authsystem.passwd.in

pre-configure:
	@if [ -f "${WRKDIR}/courier-authlib.cache" -a -s "${WRKDIR}/courier-authlib.cache" ] ; then \
		${RM} -f "${WRKDIR}/courier-authlib.cache" ; \
	fi

.if ${PKGNAMESUFFIX} == "-base"
pre-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif	# ${PKGNAMESUFFIX} == "-base"

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} ${_SHROWNGRP} -d ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.endif	# !defined(PKGNAMESUFFIX)

.include <bsd.port.post.mk>
