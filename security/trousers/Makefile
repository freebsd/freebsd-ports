# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	trousers
PORTVERSION=	0.3.10
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	The open-source TCG Software Stack

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=	gmake iconv pkgconfig
USE_GCC=	any
USE_OPENSSL=	YES
USE_LDCONFIG=	YES
USE_AUTOTOOLS=	autoconf automake libtool
USE_RC_SUBR=	tcsd
WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-gui=none --enable-static \
		--localstatedir=${PREFIX}/var \
		--with-tssuser=${USERS} --with-tssgroup=${GROUPS}
MAKE_JOBS_SAFE=	YES
SUB_FILES=	pkg-message
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}
USERS=		_tss
GROUPS=		_tss
PORTEXAMPLES=	tcsd.conf

OPTIONS_DEFINE=	EMULATOR EXAMPLES DEBUG
EMULATOR_DESC=	Build for use with the tpm-emulator

.include "Makefile.man"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMULATOR}
PKGNAMESUFFIX+=	-no_tddl
LIB_DEPENDS+=	tddl.1:${PORTSDIR}/emulators/tpm-emulator

EXTRA_PATCHES=	${FILESDIR}/extra-patch-src-tcs-Makefile.am \
		${FILESDIR}/extra-patch-src-tcsd-Makefile.am \
		${FILESDIR}/extra-patch-src-tddl-Makefile.am
# The emulator has already a libttddl.so, so comment out trousers' libtddl in the pkg-plist
PLIST_SUB+=	TDDL="@comment "
.else
PKGNAMESUFFIX+=	-tddl
CONFLICTS+=	tpm-emulator-[0-9]*
PLIST_SUB+=	TDDL=""
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

run-autotools:	run-autotools-autoreconf

run-autotools-autoreconf:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -i

.if ${PORT_OPTIONS:MEXAMPLES}
post-install: install-examples
.endif

install-examples:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} -o ${USERS} -g ${GROUPS} -m 0600 \
		${WRKSRC}/dist/tcsd.conf ${EXAMPLESDIR}/tcsd.conf

post-install:
	@[ -f ${PREFIX}/etc/tcsd.conf ] || \
		${INSTALL_DATA} ${EXAMPLESDIR}/tcsd.conf ${PREFIX}/etc/tcsd.conf
	@${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 /var/run/tpm
	@${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 /var/run/ima
	@${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 ${PREFIX}/var/lib/tpm
	@${CAT} ${PKGMESSAGE}

add-plist-post:
	@(${ECHO_CMD} "@cwd /"; \
	 ${ECHO_CMD} "@unexec ${RMDIR} var/run/tpm 2>/dev/null || true"; \
	 ${ECHO_CMD} "@exec ${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 var/run/tpm"; \
	 ${ECHO_CMD} "@unexec ${RMDIR} var/run/ima 2>/dev/null || true"; \
	 ${ECHO_CMD} "@exec ${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 var/run/ima"; \
	 ) >> ${TMPPLIST}

.include <bsd.port.mk>
