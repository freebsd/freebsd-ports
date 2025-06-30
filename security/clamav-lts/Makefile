PORTNAME=	clamav
DISTVERSION=	1.0.8
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	https://www.clamav.net/downloads/production/
PKGNAMESUFFIX=	-lts

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Open-source (GPL) anti-virus engine (LTS Feature Release)
WWW=		https://www.clamav.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${RUST_DEFAULT}>=1.56.0:lang/${RUST_DEFAULT}
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c \
		libmspack.so:archivers/libmspack \
		libpcre2-8.so:devel/pcre2

USES=		cmake cpe gnome iconv ncurses pkgconfig ssl
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_RC_SUBR=	clamav_clamd clamav_freshclam

CMAKE_ARGS=	-DDATABASE_DIRECTORY:STRING=${_DBDIR} \
		-DOPENSSL_CRYPTO_LIBRARY=${OPENSSLLIB}/libcrypto.so \
		-DOPENSSL_INCLUDE_DIR=${OPENSSLINC} \
		-DOPENSSL_ROOT_DIR=${OPENSSLBASE} \
		-DOPENSSL_SSL_LIBRARY=${OPENSSLLIB}/libssl.so
CMAKE_ON=	ENABLE_EXTERNAL_MSPACK

TEST_TARGET=	check

CONFLICTS_INSTALL=	clamav-lts

SUB_FILES=	pkg-message
SUB_LIST+=	CHMOD=${CHMOD} \
		CHOWN=${CHOWN} \
		CLAMAV_CLAMD_PIDFILE=${_CLAMAV_CLAMD_PIDFILE} \
		CLAMAV_CLAMD_SOCKET=${_CLAMAV_CLAMD_SOCKET} \
		CLAMAV_MILTER_SOCKET=${_CLAMAV_MILTER_SOCKET} \
		CLAMAVGROUP=${_CLAMAVGROUP} \
		CLAMAVUSER=${_CLAMAVUSER} \
		DBDIR=${_DBDIR} \
		LOGDIR=${_LOGDIR} \
		RUNDIR=${_RUNDIR}

USERS=		${_CLAMAVUSER}
GROUPS=		${_CLAMAVGROUP} mail

PLIST_SUB+=	CLAMAVGROUP=${_CLAMAVGROUP} \
		CLAMAVUSER=${_CLAMAVUSER} \
		DBDIR=${_DBDIR} \
		LOGDIR=${_LOGDIR} \
		RUNDIR=${_RUNDIR}

OPTIONS_DEFINE=	ARC ARJ DOCS EXPERIMENTAL LHA MILTER STDERR TESTS UNRAR UNZOO

OPTIONS_DEFAULT=	ARC ARJ MILTER UNRAR UNZOO
OPTIONS_SUB=		yes

ARC_DESC=		Enable arch archives support
ARJ_DESC=		Enable arj archives support
EXPERIMENTAL_DESC=	Build experimental code
LHA_DESC=		Enable lha archives support
MILTER_DESC=		Compile the milter interface
STDERR_DESC=		Print logs to stderr instead of stdout
TESTS_DESC=		Build with test enabled (`make test` requires it)
UNZOO_DESC=		Enable zoo archives support

ARC_RUN_DEPENDS=		arc:archivers/arc
ARJ_RUN_DEPENDS=		arj:archivers/arj
EXPERIMENTAL_CMAKE_BOOL=	ENABLE_EXPERIMENTAL
LHA_RUN_DEPENDS=		lha:archivers/lha
.if !exists(/usr/lib/libmilter.so)
MILTER_LIB_DEPENDS=		libmilter.so:mail/libmilter
.endif
MILTER_USE=			RC_SUBR=clamav_milter
.if !exists(/usr/lib/libmilter.so)
MILTER_USE+=			localbase
.endif
MILTER_CMAKE_BOOL=		ENABLE_MILTER
STDERR_EXTRA_PATCHES=		${FILESDIR}/extra-patch-common_output.c
TESTS_BUILD_DEPENDS=		${LOCALBASE}/include/check.h:devel/check
TESTS_USES=			python:build
TESTS_CMAKE_BOOL=		ENABLE_TESTS
UNRAR_CMAKE_BOOL=		ENABLE_UNRAR
UNZOO_RUN_DEPENDS=		unzoo:archivers/unzoo

_CLAMAVUSER?=	clamav
_CLAMAVGROUP?=	clamav

_CLAMAV_CLAMD_SOCKET?=	${_RUNDIR}/clamd.sock
_CLAMAV_CLAMD_PIDFILE?=	${_RUNDIR}/clamd.pid
_CLAMAV_MILTER_SOCKET?=	${_RUNDIR}/clmilter.sock

_DBDIR=		/var/db/clamav
_LOGDIR=	/var/log/clamav
_RUNDIR=	/var/run/clamav

_SED_CONF=	-E -e 's|^\#?(Example)$$|\#\1|' -e \
		's|^\#?((Update)?LogFile) .*/([a-z]+\.log)$$|\1 ${_LOGDIR}/\3|' \
		-e 's|^\#?(PidFile) .*/([a-z\-]+\.pid)$$|\1 ${_RUNDIR}/\2|' -e \
		's|^\#?(LocalSocket) .*$$|\1 ${_CLAMAV_CLAMD_SOCKET}|' -e \
		's|^\#?(User) .*$$|\1 ${_CLAMAVUSER}|' -e \
		's|^\#?(AllowSupplementaryGroups).*$$|\1 yes|' -e \
		's|^\#?(ScanMail).*$$|\1 yes|' -e \
		's|^\#?(DatabaseDirectory) .*$$|\1 ${_DBDIR}|' -e \
		's|^\#?(DatabaseOwner) .*$$|\1 ${_CLAMAVUSER}|' -e \
		's|^\#?(FixStaleSocket).*$$|\1 yes|' -e \
		's|^\#?(NotifyClamd) .*$$|\1 ${PREFIX}/etc/clamd.conf|' -e \
		's|^\#?(MilterSocket) */tmp.*$$|\1 ${_CLAMAV_MILTER_SOCKET}|' \
		-e 's|^\#?(ClamdSocket).*$$|\1 unix:${_CLAMAV_CLAMD_SOCKET}|'

post-patch:
	@${REINPLACE_CMD} ${_SED_CONF} \
		${WRKSRC}/etc/clamd.conf.sample \
		${WRKSRC}/etc/freshclam.conf.sample \
		${WRKSRC}/etc/clamav-milter.conf.sample

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/clamav-config.h ${STAGEDIR}${PREFIX}/include
	@${MKDIR} ${STAGEDIR}${_DBDIR} \
		  ${STAGEDIR}${_LOGDIR} \
		  ${STAGEDIR}${_RUNDIR}

post-install-DOCS-on:
	${MV} ${STAGEDIR}${PREFIX}/share/doc/ClamAV ${STAGEDIR}${DOCSDIR}

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/ClamAV

pre-test-TESTS-off:
	@${ECHO_MSG} '******************************************************************' && \
	${ECHO_MSG} '***** You need to enable TESTS option to execute `make test` *****' && \
	${ECHO_MSG} '******************************************************************' && \
	${FALSE}

.include <bsd.port.mk>
