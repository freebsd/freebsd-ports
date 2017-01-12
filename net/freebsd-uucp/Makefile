# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freebsd-uucp
DISTVERSIONPREFIX=	r
DISTVERSION=	1_07_3
PORTREVISION=	3
CATEGORIES=	net comms ipv6
PKGNAMESUFFIX?=	${PAM_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	FreeBSD-modified Taylor UUCP (unix-to-unix copy program)

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
MAKE_ENV+=	CSTD=gnu99

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
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 110000
MAKE_ENV+=	MINUSLPAM=-lpam
.endif
CONFLICTS?=	freebsd-uucp-1.*
.else
CONFLICTS?=	freebsd-uucp-pam-1.*
.endif

.if ${PORT_OPTIONS:MENCRYPTED_PASSWORDS}
MAKE_ENV+=	WITH_ENCRYPTED_PASSWORDS=1
.endif

post-extract:
	${REINPLACE_CMD} -e 's|doc ||' ${WRKSRC}/uucp/Makefile
	${REINPLACE_CMD} -e 's|VERSION=.*|VERSION=${PORTVERSION}|' \
		${WRKSRC}/uucp/common_sources/configure \
		${WRKSRC}/uucp/Makefile.inc
	${REINPLACE_CMD} -e 's|(owner)|(uucpowner)|' \
		${WRKSRC}/uucp/uustat/Makefile
	${REINPLACE_CMD} -e 's|0770|0750|' ${WRKSRC}/local.mtree
	${REINPLACE_CMD} -e 's|getline (|get_line (|g' \
		${WRKSRC}/uucp/libuucp/getlin.c

do-configure:
	${REINPLACE_CMD} -e "s=/usr/local/=${PREFIX}/=" \
		${FIXME:S,^,${WRKSRC}/,}
.if ${PORT_OPTIONS:MVAR_LOG}
	${REINPLACE_CMD} \
		-e "s=/var/spool/uucp/Log=/var/log/uucp/Log=" \
		-e "s=/var/spool/uucp/Debug=/var/log/uucp/Debug=" \
		-e "s=/var/spool/uucp/Stats=/var/log/uucp/Stats=" \
		${VARLOG:S,^,${WRKSRC}/,}
	@${ECHO_CMD} "   .." >> ${WRKSRC}/uucp.mtree
	@${ECHO_CMD} "/set uname=root gname=wheel mode=0755" \
		>> ${WRKSRC}/uucp.mtree
	@${ECHO_CMD} "   log" >> ${WRKSRC}/uucp.mtree
	@${ECHO_CMD} "/set uname=uucp gname=uucp mode=0775" \
		>> ${WRKSRC}/uucp.mtree
	@${ECHO_CMD} "       uucp" >> ${WRKSRC}/uucp.mtree
	@${ECHO_CMD} "       .." >> ${WRKSRC}/uucp.mtree
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
	${MKDIR} ${STAGEDIR}/var

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mtree ${STAGEDIR}${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/uucp.mtree ${STAGEDIR}${PREFIX}/etc/mtree/uucp-var.mtree
	${INSTALL_DATA} ${WRKSRC}/local.mtree ${STAGEDIR}${PREFIX}/etc/mtree/uucp-local.mtree
	${INSTALL_DATA} ${WRKSRC}/uucp/doc/uucp.info ${STAGEDIR}${PREFIX}/info/

.include <bsd.port.mk>
