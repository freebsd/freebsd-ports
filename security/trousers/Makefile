# Created by: Sebastian Schuetz <sschuetz@fhm.edu>
# $FreeBSD$

PORTNAME=	trousers
PORTVERSION=	0.3.6
PORTREVISION=	3
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
GNU_CONFIGURE=	YES
MAKE_JOBS_SAFE=	YES
SUB_FILES=	pkg-message
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}

USERS=		_tss
GROUPS=		_tss

.include "Makefile.man"

CONFIGURE_ARGS=	--with-gui=none --enable-static \
		--localstatedir=${PREFIX}/var \
		--with-tssuser=${USERS} --with-tssgroup=${GROUPS}

OPTIONS_DEFINE=	EMULATOR DEBUG
EMULATOR_DESC=	Build for use with the tpm-emulator

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMULATOR}
PKGNAMESUFFIX+=	-no_tddl
LIB_DEPENDS+=	tddl.1:${PORTSDIR}/emulators/tpm-emulator

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${top_builddir}/src/tddl/libtddl.a|${LOCALBASE}/lib/libtddl.a|' \
			${WRKSRC}/src/tcs/Makefile.am \
			${WRKSRC}/src/tcsd/Makefile.am
	@${REINPLACE_CMD} -e \
		's|libtddl\.a||g' \
			${WRKSRC}/src/tddl/Makefile.am

# The emulator has already a libttddl.so, so comment out trousers' libtddl in the pkg-plist
PLIST_SUB+=	TDDL="@comment "
.else
PKGNAMESUFFIX+=	-tddl
CONFLICTS+=	tpm-emulator-0*
PLIST_SUB+=	TDDL=""
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

run-autotools:	run-autotools-autoreconf

run-autotools-autoreconf:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -i

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} -o ${USERS} -g ${GROUPS} -m 0600 \
		${WRKSRC}/dist/tcsd.conf ${EXAMPLESDIR}/tcsd.conf
	@[ -f ${PREFIX}/etc/tcsd.conf ] || \
		${CP} -p ${EXAMPLESDIR}/tcsd.conf ${PREFIX}/etc/tcsd.conf
	@${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 /var/run/tpm
	@${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 /var/run/ima
	@${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 ${PREFIX}/var/lib/tpm
	@${CAT} ${PKGMESSAGE}

add-plist-post:
	@${ECHO_CMD} "@cwd /"								>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} var/run/tpm 2>/dev/null || true"			>> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 var/run/tpm"	>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} var/run/ima 2>/dev/null || true"			>> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${INSTALL} -d -o ${USERS} -g ${GROUPS} -m 0700 var/run/ima"	>> ${TMPPLIST}

.include <bsd.port.mk>
