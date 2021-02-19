# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freebsd-uucp
PORTREVISION=	3
DISTVERSIONPREFIX=	r
DISTVERSION=	1_07_4
CATEGORIES=	net comms
PKGNAMESUFFIX?=	${PAM_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	FreeBSD-modified Taylor UUCP (unix-to-unix copy program)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/uucp/COPYING

PORTSCOUT=	limit:^1_

USES=		fakeroot

USE_GITHUB=	yes
GH_ACCOUNT=	dinoex

PKGMESSAGE=	${WRKDIR}/pkg-message
INFO=	uucp
VARLOG=	uucp/common_sources/policy.h uucp/uucico/uucico.8 \
	uucp/uucp/uucp.1 uucp/uux/uux.1 uucp/uuxqt/uuxqt.8
FIXME=	etc/periodic/daily/340.uucp etc/periodic/daily/410.status-uucp \
	etc/periodic/weekly/300.uucp

# fix errros for -std=iso9899:1999 in FreeBSD 5.1
MAKE_ENV+=	CSTD=gnu99 WITHOUT_PIE=true

OPTIONS_DEFINE=PAM ENCRYPTED_PASSWORDS VAR_LOG
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes
NO_OPTIONS_SORT=yes
ENCRYPTED_PASSWORDS_DESC=	use encrypted passwords in etc/uucp/sys
VAR_LOG_DESC=			put logfiles into /var/log

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPAM}
PAM_SUFFIX=	-pam
MAKE_ENV+=	WITH_PAM=${WITH_PAM}
.if ${OPSYS} == FreeBSD
MAKE_ENV+=	MINUSLPAM=-lpam
.endif
.endif

.if ${PORT_OPTIONS:MENCRYPTED_PASSWORDS}
MAKE_ENV+=	WITH_ENCRYPTED_PASSWORDS=1
.endif

do-configure:
	${REINPLACE_CMD} -e 's|doc ||' ${WRKSRC}/uucp/Makefile
	${REINPLACE_CMD} -e "s=/usr/local/=${PREFIX}/=" \
		${FIXME:S,^,${WRKSRC}/,}
.if ${PORT_OPTIONS:MVAR_LOG}
	${REINPLACE_CMD} \
		-e "s=/var/spool/uucp/Log=/var/log/uucp/Log=" \
		-e "s=/var/spool/uucp/Debug=/var/log/uucp/Debug=" \
		-e "s=/var/spool/uucp/Stats=/var/log/uucp/Stats=" \
		${VARLOG:S,^,${WRKSRC}/,}
.endif
.if ${PORT_OPTIONS:MENCRYPTED_PASSWORDS}
	${REINPLACE_CMD} \
		-e "s=HAVE_ENCRYPTED_PASSWORDS.*=HAVE_ENCRYPTED_PASSWORDS 1=" \
		${WRKSRC}/uucp/common_sources/policy.h
.endif
	@${CAT} ${MASTERDIR}/pkg-message > ${WRKDIR}/pkg-message
.if ${PORT_OPTIONS:MPAM}
	@${ECHO_MSG} "" >> ${WRKDIR}/pkg-message
	@${ECHO_MSG} "Add this lines to your pam.conf:" >> ${WRKDIR}/pkg-message
	@${CAT} ${FILESDIR}/uucp-pam.conf >> ${WRKDIR}/pkg-message
.endif
	(cd ${CONFIGURE_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} configure)

pre-install:
	${MKDIR} ${STAGEDIR}/var ${STAGEDIR}${PREFIX}/etc/mtree
	${INSTALL_DATA} ${WRKSRC}/etc/mtree/uucp-var.mtree \
		${STAGEDIR}${PREFIX}/etc/mtree/uucp-var.mtree
	${INSTALL_DATA} ${WRKSRC}/etc/mtree/uucp-local.mtree \
		${STAGEDIR}${PREFIX}/etc/mtree/uucp-local.mtree

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/uucp/doc/uucp.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
.if ${PORT_OPTIONS:MVAR_LOG}
	${MKDIR} ${STAGEDIR}/var/log/uucp
.endif

.include <bsd.port.mk>
