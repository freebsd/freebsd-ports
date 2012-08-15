# New ports collection makefile for:	trousers
# Date created:				18 Sep 2007
# Whom:					Sebastian Schuetz <sschuetz@fhm.edu>
#
# $FreeBSD$
#

PORTNAME=	trousers
PORTVERSION=	0.3.6
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The open-source TCG Software Stack

USE_GMAKE=	YES
USE_ICONV=	YES
USE_OPENSSL=	YES
USE_LDCONFIG=	YES
USE_PKGCONFIG=	YES
USE_AUTOTOOLS=	autoconf automake libtool
GNU_CONFIGURE=	YES
MAKE_JOBS_SAFE=	YES

USE_RC_SUBR=	tcsd
SUB_FILES=	pkg-message
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}

USERS=		_tss
GROUPS=		_tss

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

.include "Makefile.man"

CONFIGURE_ARGS=	--with-gui=none --enable-static \
		--localstatedir=${PREFIX}/var \
		--with-tssuser=${USERS} --with-tssgroup=${GROUPS}

OPTIONS=	EMULATOR	"Build for use with the tpm-emulator" off \
		DEBUG		"Build with debugging flags" off

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_EMULATOR)
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

.if defined(WITH_DEBUG)
PKGNAMESUFFIX+=	-debug
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

.include <bsd.port.post.mk>
