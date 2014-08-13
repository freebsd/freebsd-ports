# Created by: rskinner port_maintainer@herveybayaustralia.com.au
# $FreeBSD: head/net/linux-f10-nss_ldap/Makefile 362935 2014-07-25 21:43:13Z rene $

PORTNAME=	nss_ldap
PORTVERSION=	${NSS_LDAP_VERSION}
CATEGORIES=	net linux
MASTER_SITES=	ftp://ftp.pbone.net/mirror/archive.fedoraproject.org/fedora/linux/updates/testing/10/i386/ \
		http://archives.fedoraproject.org/pub/archive/fedora/linux/updates/testing/10/i386/ \
		http://herveybayaustralia.com.au/ports/distfiles/
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${NSS_LDAP_VERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RFC 2307 NSS Module (Linux Fedora 10)

#LICENSE=	GPLv2
#NO_LICENSES_INSTALL=yes	# license framework does not rm the "share" directory

OPTIONS_DEFINE=	DOCS PAM

NSS_LDAP_VERSION=264

USE_LINUX_RPM=	yes
USE_LINUX_PREFIX=yes
LINUX_DIST_VER=	10
RPMVERSION=	6.fc10
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${NSS_LDAP_VERSION}

MANPREFIX=	${PREFIX}/usr/share

OPTIONS_SUB=	yes

PORTDOCS=	ANNOUNCE.nss_ldap AUTHORS.nss_ldap COPYING.nss_ldap \
		ChangeLog.nss_ldap NEWS.nss_ldap README.TLS README.nss_ldap \
		ldap.conf.nss_ldap ldapns.schema ns-pwd-policy.schema \
		nsswitch.ldap

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPAM}
PORTDOCS+=	AUTHORS.pam_ldap COPYING.LIB.pam_ldap COPYING.pam_ldap \
		ChangeLog.pam_ldap NEWS.pam_ldap README.pam_ldap \
		ldap.conf.pam_ldap pam.d/chfn pam.d/chsh pam.d/ftp \
		pam.d/gdm pam.d/halt pam.d/imap pam.d/kde pam.d/linuxconf \
		pam.d/linuxconf-pair pam.d/login pam.d/mcserv pam.d/other \
		pam.d/passwd pam.d/pop pam.d/poweroff pam.d/ppp pam.d/reboot \
		pam.d/rexec pam.d/rlogin pam.d/rsh pam.d/samba pam.d/shutdown \
		pam.d/ssh pam.d/su pam.d/vlock pam.d/xdm pam.d/xlock \
		pam.d/xscreensaver pam.d/xserver
.endif

pre-fetch:
.if !${PORT_OPTIONS:MPAM}
	@${ECHO_MSG} "Select PAM if you require more advanced ldap support in the linuxulator"
.endif

post-extract:
	@if [ -f ${WRKDIR}/etc/ldap.conf ]; then \
		${MV} ${WRKDIR}/etc/ldap.conf ${WRKDIR}/etc/ldap.conf.dist; \
	fi
.if !${PORT_OPTIONS:MPAM}
	@if [ -f ${WRKDIR}/lib/security/pam_ldap.so ]; then \
		${RM} -rf ${WRKDIR}/lib/; \
	fi
	@if [ -f ${WRKDIR}/usr/share/doc/${PORTNAME}-${NSS_LDAP_VERSION}/COPYING.pam_ldap ]; then \
		${RM} ${WRKDIR}/usr/share/doc/${PORTNAME}-${NSS_LDAP_VERSION}/*.pam*; \
		${RM} -rf ${WRKDIR}/usr/share/doc/${PORTNAME}-${NSS_LDAP_VERSION}/pam.d; \
	fi
	@if [ -f ${WRKDIR}/usr/share/man/man5/pam_ldap.5.gz ]; then \
		${RM} ${WRKDIR}/usr/share/man/man5/pam_ldap.5.gz; \
	fi
.else
.if !${PORT_OPTIONS:MDOCS}
	@if [ -d ${WRKDIR}/usr/share/doc/${PORTNAME}-${NSS_LDAP_VERSION}/pam.d ]; then \
		${RM} -rf ${WRKDIR}/usr/share/doc/${PORTNAME}-${NSS_LDAP_VERSION}/pam.d/; \
	fi
.endif
.endif

.include <bsd.port.mk>
