# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freebsd-uucp
PORTVERSION=	1.07.3
PORTREVISION=	1
CATEGORIES=	net comms ipv6
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=dinoex
PKGNAMESUFFIX?=	${PAM_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	FreeBSD-modified Taylor UUCP (unix-to-unix copy program)

NEED_ROOT=	yes

USE_BZIP2=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
INFO=	uucp
VARLOG=	uucp/common_sources/policy.h uucp/uucico/uucico.8 \
	uucp/uucp/uucp.1 uucp/uux/uux.1 uucp/uuxqt/uuxqt.8
POLICY=	uucp/common_sources/policy.h
FIXME=	etc/periodic/daily/340.uucp etc/periodic/daily/410.status-uucp \
	etc/periodic/weekly/300.uucp
BPKGNAME=	base-uucp-1.06.1

# fix errros for -std=iso9899:1999 in FreeBSD 5.1
MAKE_ENV+=	CSTD=gnu99

OPTIONS_DEFINE=PAM ENCRYPTED_PASSWORDS VAR_LOG
OPTIONS_DEFAULT=
NO_OPTIONS_SORT=yes
ENCRYPTED_PASSWORDS_DESC=	use encrypted passwords in etc/uucp/sys
VAR_LOG_DESC=			put logfiles into /var/log

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPAM}
PAM_SUFFIX=	-pam
MAKE_ENV+=	WITH_PAM=${WITH_PAM}
CONFLICTS?=	freebsd-uucp-1.*
.else
CONFLICTS?=	freebsd-uucp-pam-1.*
.endif

.if ${PORT_OPTIONS:MENCRYPTED_PASSWORDS}
MAKE_ENV+=	WITH_ENCRYPTED_PASSWORDS=1
.endif

.if ${OSVERSION} > 1000000
BUILD_DEPENDS=	cvs:${PORTSDIR}/devel/cvs
.endif

post-extract:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} extract)
	${REINPLACE_CMD} -e 's|doc ||' ${WRKSRC}/uucp/Makefile

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
		${WRKSRC}/${POLICY}
.endif
	@${CAT} pkg-message > ${WRKDIR}/pkg-message
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
	-${MKDIR} ${STAGEDIR}${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/uucp/doc/uucp.info ${STAGEDIR}${PREFIX}/info/
	${CHOWN} uucp:uucp ${STAGEDIR}${PREFIX}/etc/uucp
	${CHMOD} 750 ${STAGEDIR}${PREFIX}/etc/uucp
	@${ECHO_CMD} "updating ${ROOTDIR}/etc/services"
	@${CP} ${ROOTDIR}/etc/services ${ROOTDIR}/etc/services.bak
	@(grep -v ^suucp ${ROOTDIR}/etc/services.bak; \
	${ECHO_CMD} "suucp           4031/tcp   #UUCP over SSL"; \
	${ECHO_CMD} "suucp           4031/udp   #UUCP over SSL" ) \
		> ${ROOTDIR}/etc/services
.if !defined(BATCH)
	@if test "$$(pw usershow uucp)" != "uucp:*:66:66::0:0:UUCP pseudo-user:/var/spool/uucppublic:${PREFIX}/libexec/uucp/uucico"; then \
	pw usermod uucp -s ${PREFIX}/libexec/uucp/uucico; fi
	@pw usershow uucp
.endif
	@${ECHO_MSG} "Use the 'make upgrade' command to copy your old configuration"
	@${ECHO_MSG} "files from /etc/uucp to the new location in ${PREFIX}/etc/uucp"
	@${ECHO_MSG}

upgrade:
	@${ECHO_MSG} "Copying old configuration files from /etc/uucp to ${PREFIX}/etc/uucp"
	@${CP} -rp /etc/uucp ${PREFIX}/etc/uucp

.include <bsd.port.mk>
