# Created by: rskinner port_maintainer@herveybayaustralia.com.au
# $FreeBSD$

PORTNAME=	nss_ldap
PORTVERSION=	264
PORTREVISION=	1
CATEGORIES=	net linux
MASTER_SITES=	ftp://ftp.pbone.net/mirror/archive.fedoraproject.org/fedora/linux/updates/testing/10/i386/ \
		http://archives.fedoraproject.org/pub/archive/fedora/linux/updates/testing/10/i386/ \
		http://herveybayaustralia.com.au/ports/distfiles/

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RFC 2307 NSS Module (Linux Fedora 10)

#LICENSE=	GPLv2
#NO_LICENSES_INSTALL=yes	# license framework does not rm the "share" directory

RPMVERSION=	6.fc10
USES=		linux:f10
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS PAM
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

post-patch:
	@if [ -f ${WRKSRC}/etc/ldap.conf ]; then \
		${MV} ${WRKSRC}/etc/ldap.conf ${WRKSRC}/etc/ldap.conf.dist; \
	fi
.if !${PORT_OPTIONS:MPAM}
	@if [ -f ${WRKSRC}/lib/security/pam_ldap.so ]; then \
		${RM} -r ${WRKSRC}/lib/; \
	fi
	@if [ -f ${WRKSRC}/usr/share/doc/${PORTNAME}-${PORTVERSION}/COPYING.pam_ldap ]; then \
		${RM} ${WRKSRC}/usr/share/doc/${PORTNAME}-${PORTVERSION}/*.pam*; \
		${RM} -r ${WRKSRC}/usr/share/doc/${PORTNAME}-${PORTVERSION}/pam.d; \
	fi
	@if [ -f ${WRKSRC}/usr/share/man/man5/pam_ldap.5.gz ]; then \
		${RM} ${WRKSRC}/usr/share/man/man5/pam_ldap.5.gz; \
	fi
.else
.if !${PORT_OPTIONS:MDOCS}
	@if [ -d ${WRKSRC}/usr/share/doc/${PORTNAME}-${PORTVERSION}/pam.d ]; then \
		${RM} -r ${WRKSRC}/usr/share/doc/${PORTNAME}-${PORTVERSION}/pam.d/; \
	fi
.endif
.endif

.include <bsd.port.mk>
