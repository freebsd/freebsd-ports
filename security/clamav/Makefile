# $FreeBSD$

PORTNAME=	clamav
PORTVERSION=	0.102.2
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	https://www.clamav.net/downloads/production/

MAINTAINER=	yasu@utahime.org
COMMENT=	Command line virus scanner written entirely in C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmspack.so:archivers/libmspack \
		libltdl.so:devel/libltdl \
		libcurl.so:ftp/curl

USES=		compiler cpe gmake gnome libtool ncurses pathfix pkgconfig ssl
USE_RC_SUBR=	clamav-clamd clamav-freshclam
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB+=	DBDIR=${DBDIR} \
		LOGDIR=${LOGDIR} \
		RUNDIR=${RUNDIR} \
		CLAMAVUSER=${CLAMAVUSER} \
		CLAMAVGROUP=${CLAMAVGROUP}

CONFIGURE_ARGS=	--libdir=${LOCALBASE}/lib \
		--with-dbdir=${DBDIR} \
		--enable-bigstack \
		--disable-dependency-tracking \
		--enable-clamdtop \
		--with-system-libmspack=${LOCALBASE}/lib/libmspack.so

CFLAGS_i386=	-march=i486
CPPFLAGS+=	-I${LOCALBASE}/include

# This port has a problem with -pthread,
# force to use -lthr until it's not fixed.
LDFLAGS+=	-lthr -L${LOCALBASE}/lib

SUB_FILES=	pkg-deinstall
SUB_LIST+=	DBDIR=${DBDIR} \
		LOGDIR=${LOGDIR} \
		RUNDIR=${RUNDIR} \
		CHMOD=${CHMOD} \
		CHOWN=${CHOWN} \
		CLAMAVUSER=${CLAMAVUSER} \
		CLAMAVGROUP=${CLAMAVGROUP} \
		CLAMAV_CLAMD_SOCKET=${CLAMAV_CLAMD_SOCKET} \
		CLAMAV_CLAMD_PIDFILE=${CLAMAV_CLAMD_PIDFILE} \
		CLAMAV_MILTER_SOCKET=${CLAMAV_MILTER_SOCKET}

PLIST_SUB+=	CLAMAVUSER=${CLAMAVUSER} \
		CLAMAVGROUP=${CLAMAVGROUP}

OPTIONS_DEFINE=	ARC ARJ DOCS DMG_XAR EXPERIMENTAL JSON LDAP ICONV IPV6 \
		LHA MILTER PCRE STDERR TESTS UNZOO UNRAR

OPTIONS_DEFAULT=	ARC ARJ DMG_XAR JSON MILTER PCRE UNZOO UNRAR
OPTIONS_SUB=	yes

ARC_DESC=		Enable arch archives support
ARJ_DESC=		Enable arj archives support
DMG_XAR_DESC=		Enable DMG and XAR archives support
EXPERIMENTAL_DESC=	Build experimental code
LHA_DESC=		Enable lha archives support
MILTER_DESC=		Compile the milter interface
STDERR_DESC=		Print logs to stderr instead of stdout
TESTS_DESC=		Run compile-time tests (req. python)
UNZOO_DESC=		Enable zoo archives support

ARC_RUN_DEPENDS=	arc:archivers/arc
ARJ_RUN_DEPENDS=	arj:archivers/arj
DMG_XAR_CONFIGURE_ENABLE=	xml
DMG_XAR_USE=		GNOME=libxml2
EXPERIMENTAL_CONFIGURE_ENABLE=	experimental
ICONV_CONFIGURE_WITH=	iconv
ICONV_USES=		iconv
IPV6_CONFIGURE_ENABLE=	ipv6
JSON_CONFIGURE_WITH=	libjson
JSON_LIB_DEPENDS=	libjson-c.so:devel/json-c
LDAP_LDFLAGS=		-lldap
LDAP_USE=		OPENLDAP=yes
LHA_RUN_DEPENDS=	lha:archivers/lha
MILTER_CONFIGURE_WITH=	sendmail=/usr/sbin/sendmail
MILTER_CONFIGURE_ENABLE=milter
.if !exists(/usr/lib/libmilter.so)
MILTER_LIB_DEPENDS+=	libmilter.so:mail/libmilter
.endif
MILTER_USE=		RC_SUBR=clamav-milter
PCRE_CONFIGURE_WITH=	pcre
PCRE_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
STDERR_EXTRA_PATCHES=	${FILESDIR}/extra-patch-shared_output.c
TESTS_CONFIGURE_ENABLE=	check
TESTS_BUILD_DEPENDS=	${LOCALBASE}/include/check.h:devel/check
TESTS_USES=		python:build
UNRAR_CONFIGURE_ENABLE=	unrar
UNZOO_RUN_DEPENDS=	unzoo:archivers/unzoo

CLAMAVUSER?=	clamav
CLAMAVGROUP?=	clamav

CLAMAV_CLAMD_SOCKET?=	${RUNDIR}/clamd.sock
CLAMAV_CLAMD_PIDFILE?=	${RUNDIR}/clamd.pid
CLAMAV_MILTER_SOCKET?=	${RUNDIR}/clmilter.sock

.if ${CLAMAVUSER} == "clamav"
USERS=	clamav
.endif

.if ${CLAMAVGROUP} == "clamav"
GROUPS=	clamav mail
.endif

DBDIR=		/var/db/clamav
LOGDIR=		/var/log/clamav
RUNDIR=		/var/run/clamav
PY_NO_THREAD=	${WRKDIR}/.python-has-no-threads

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

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|-lthr|g' \
			  -e 's|LC_REVISION=22|LC_REVISION=24|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} ${SED_CONF} \
		${WRKSRC}/etc/clamd.conf.sample \
		${WRKSRC}/etc/freshclam.conf.sample \
		${WRKSRC}/etc/clamav-milter.conf.sample
.if ${CHOSEN_COMPILER_TYPE} == gcc
	@${REINPLACE_CMD} -e 's|-Wno-logical-op-parentheses||' \
			  -e 's|-Wno-dangling-else||' \
		${WRKSRC}/libclamav/Makefile.am \
		${WRKSRC}/libclamav/Makefile.in \
		${WRKSRC}/libclamunrar/makefile
.endif

pre-configure-TESTS-on:
	@if ! ${PYTHON_CMD} -c "import thread" >/dev/null 2>&1; then \
		${ECHO_MSG} ""; \
		${ECHO_MSG} "==========================================================================="; \
		${ECHO_MSG} "= Unit tests REQUIRES python built with thread support, and yours is not. ="; \
		${ECHO_MSG} "= It will not be called during this build                                 ="; \
		${ECHO_MSG} "==========================================================================="; \
		${ECHO_MSG} ""; \
		${TOUCH} ${PY_NO_THREAD}; \
	fi

post-build-TESTS-on:
	@if [ ! -f "${PY_NO_THREAD}" ]; then \
		${MAKE_CMD} -C ${WRKSRC} check; \
	fi

post-install:
	${INSTALL_DATA} ${WRKSRC}/clamav-config.h ${STAGEDIR}${PREFIX}/include
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html \
		  ${STAGEDIR}${DBDIR} \
		  ${STAGEDIR}${LOGDIR} \
		  ${STAGEDIR}${RUNDIR}
	(cd ${WRKSRC}/docs/html; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html)

.include <bsd.port.post.mk>
