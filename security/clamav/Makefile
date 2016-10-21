# Created by: markun@onohara.to
# $FreeBSD$

PORTNAME=	clamav
PORTVERSION=	0.99.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.clamav.net/downloads/production/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Command line virus scanner written entirely in C

LICENSE=	GPLv2

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libcurl.so:ftp/curl

OPTIONS_DEFINE=	ARC ARJ LHA UNZOO UNRAR LLVM TESTS MILTER LDAP ICONV STDERR \
		EXPERIMENTAL DOCS IPV6 DMG_XAR JSON PCRE

ARC_DESC=		Enable arch archives support
ARJ_DESC=		Enable arj archives support
LHA_DESC=		Enable lha archives support
UNZOO_DESC=		Enable zoo archives support
UNRAR_DESC=		Enable rar archives support
LLVM_DESC=		Enable JIT Bytecode compiler (req. LLVM)
TESTS_DESC=		Run compile-time tests (req. python)
MILTER_DESC=		Compile the milter interface
STDERR_DESC=		Print logs to stderr instead of stdout
EXPERIMENTAL_DESC=	Build experimental code
DMG_XAR_DESC=		Enable DMG and XAR archives support

OPTIONS_DEFAULT=	ARC ARJ LHA UNZOO UNRAR DMG_XAR \
			JSON PCRE

ARC_RUN_DEPENDS=	arc:archivers/arc
ARJ_RUN_DEPENDS=	arj:archivers/arj
LHA_RUN_DEPENDS=	lha:archivers/lha
UNZOO_RUN_DEPENDS=	unzoo:archivers/unzoo
JSON_LIB_DEPENDS=	libjson-c.so:devel/json-c
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
UNRAR_CONFIGURE_ENABLE=	unrar
MILTER_CONFIGURE_ENABLE=milter
TESTS_CONFIGURE_ENABLE=	check
JSON_CONFIGURE_WITH=	libjson
PCRE_CONFIGURE_WITH=	pcre
TESTS_BUILD_DEPENDS=	${LOCALBASE}/include/check.h:devel/libcheck
ICONV_CONFIGURE_ON=	--with-iconv
ICONV_CONFIGURE_OFF=	--without-iconv
ICONV_USES=		iconv
LLVM_USES=		compiler:c++11-lib
EXPERIMENTAL_CONFIGURE_ENABLE=	experimental
IPV6_CONFIGURE_ENABLE=	ipv6
DMG_XAR_CONFIGURE_ENABLE=	xml
DMG_XAR_USE=		GNOME=libxml2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		cpe gmake libtool ncurses pathfix
INSTALL_TARGET=	install-strip
USE_RC_SUBR=	clamav-clamd clamav-freshclam

PORTDOCS=	*

DBDIR=		/var/db/clamav
LOGDIR=		/var/log/clamav
RUNDIR=		/var/run/clamav
PLIST_SUB+=	DBDIR=${DBDIR} \
		LOGDIR=${LOGDIR} \
		RUNDIR=${RUNDIR} \
		CLAMAVUSER=${CLAMAVUSER} \
		CLAMAVGROUP=${CLAMAVGROUP}
PY_NO_THREAD=	${WRKDIR}/.python-has-no-threads
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	--libdir=${PREFIX}/lib \
		--with-dbdir=${DBDIR} \
		--with-zlib=/usr \
		--disable-clamuko \
		--disable-clamav \
		--enable-bigstack \
		--enable-readdir_r \
		--enable-gethostbyname_r \
		--disable-dependency-tracking \
		--enable-clamdtop
CPPFLAGS+=	-I${LOCALBASE}/include

# This port has a problem with -pthread,
# force to use -lthr until it's not fixed.
LDFLAGS+=	-lthr -L${LOCALBASE}/lib

CONFLICTS?=	clamav-milter-[0-9]*

CLAMAVUSER?=	clamav
CLAMAVGROUP?=	clamav

CLAMAV_CLAMD_SOCKET?=	${RUNDIR}/clamd.sock
CLAMAV_MILTER_SOCKET?=	${RUNDIR}/clmilter.sock

SUB_FILES=	pkg-deinstall
SUB_LIST+=	DBDIR=${DBDIR} \
		LOGDIR=${LOGDIR} \
		RUNDIR=${RUNDIR} \
		CHMOD=${CHMOD} \
		CHOWN=${CHOWN} \
		CLAMAVUSER=${CLAMAVUSER} \
		CLAMAVGROUP=${CLAMAVGROUP} \
		CLAMAV_CLAMD_SOCKET=${CLAMAV_CLAMD_SOCKET} \
		CLAMAV_MILTER_SOCKET=${CLAMAV_MILTER_SOCKET}

SED_CONF=	-E -e 's|^\#?(Example)$$|\#\1|' \
		-e 's|^\#?((Update)?LogFile) .*/([a-z]+\.log)$$|\1 ${LOGDIR}/\3|' \
		-e 's|^\#?(PidFile) .*/([a-z\-]+\.pid)$$|\1 ${RUNDIR}/\2|' \
		-e 's|^\#?(LocalSocket) .*$$|\1 ${CLAMAV_CLAMD_SOCKET}|' \
		-e 's|^\#?(User) .*$$|\1 ${CLAMAVUSER}|' \
		-e 's|^\#?(AllowSupplementaryGroups).*$$|\1 yes|' \
		-e 's|^\#?(ScanMail).*$$|\1 yes|' \
		-e 's|^\#?(DatabaseDirectory) .*$$|\1 ${DBDIR}|' \
		-e 's|^\#?(DatabaseOwner) .*$$|\1 ${CLAMAVUSER}|' \
		-e 's|^\#?(FixStaleSocket).*$$|\1 yes|' \
		-e 's|^\#?(NotifyClamd) .*$$|\1 ${PREFIX}/etc/clamd.conf|' \
		-e 's|^\#?(MilterSocket) */tmp.*$$|\1 ${CLAMAV_MILTER_SOCKET}|' \
		-e 's|^\#?(ClamdSocket).*$$|\1 unix:${CLAMAV_CLAMD_SOCKET}|'

PLIST_SUB+=	CLAMAVUSER=${CLAMAVUSER} \
		CLAMAVGROUP=${CLAMAVGROUP}

.include <bsd.port.options.mk>

.if ${CLAMAVUSER} == "clamav"
USERS=	clamav
.endif

.if ${CLAMAVGROUP} == "clamav"
GROUPS=	clamav mail
.endif

.if ${PORT_OPTIONS:MLLVM} && ( ${ARCH} == "i386" || ${ARCH} == "amd64" )
CONFIGURE_ARGS+=--enable-llvm --with-system-llvm=${LOCALBASE}/llvm${LLVMVER}
BUILD_DEPENDS+=	llvm${LLVMVER}>=0:devel/llvm${LLVMVER}
# Beware: ClamAV doesn't support LLVM 3.7 or higher yet
LLVMVER=	36
. if ${PORT_OPTIONS:MTESTS}
USES+=		python:build
. endif
.else
CONFIGURE_ARGS+=--disable-llvm
.endif

.if ${PORT_OPTIONS:MMILTER}
USE_RC_SUBR+=	clamav-milter
. if ${PORT_OPTIONS:MLDAP} && exists(${LOCALBASE}/lib/libldap.so)
USE_OPENLDAP=	yes
LDFLAGS+=	-lldap
. endif

. if !exists(/usr/lib/libmilter.a) || exists(${LOCALBASE}/lib/libmilter.a)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:mail/libmilter
CONFIGURE_ARGS+=--with-sendmail=${LOCALBASE}/sbin/sendmail
LDFLAGS+=	-L${LOCALBASE}/lib
. else
CONFIGURE_ARGS+=--with-sendmail=/usr/sbin/sendmail
. endif
.endif

.if ${PORT_OPTIONS:MSTDERR}
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-shared_output.c
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS+=	-march=i486
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|-lthr|g' \
			  -e 's|LC_REVISION=22|LC_REVISION=24|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} ${SED_CONF} \
		${WRKSRC}/etc/clamd.conf.sample \
		${WRKSRC}/etc/freshclam.conf.sample \
		${WRKSRC}/etc/clamav-milter.conf.sample
	@${REINPLACE_CMD} -e 's|0x100000000|0x100000000ULL|g' \
		${WRKSRC}/libclamunrar/unrar.c

.if ${PORT_OPTIONS:MLLVM} && ${PORT_OPTIONS:MTESTS}
pre-configure:
	@if ! ${PYTHON_CMD} -c "import thread" >/dev/null 2>&1; then \
		${ECHO_MSG} ""; \
		${ECHO_MSG} "==========================================================================="; \
		${ECHO_MSG} "= Unit tests REQUIRES python built with thread support, and yours is not. ="; \
		${ECHO_MSG} "= It will not be called during this build                                 ="; \
		${ECHO_MSG} "==========================================================================="; \
		${ECHO_MSG} ""; \
		${TOUCH} ${PY_NO_THREAD}; \
	fi
.endif

.if ${PORT_OPTIONS:MTESTS}
post-build:
	@if [ ! -f "${PY_NO_THREAD}" ]; then \
		${MAKE_CMD} -C ${WRKSRC} check; \
	fi
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/clamav-config.h ${STAGEDIR}${PREFIX}/include
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html \
		  ${STAGEDIR}${DBDIR} \
		  ${STAGEDIR}${LOGDIR} \
		  ${STAGEDIR}${RUNDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.post.mk>
