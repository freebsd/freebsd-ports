# Created by: rskinner port_maintainer@herveybayaustralia.com.au
# $FreeBSD$

PORTNAME=	nss_ldap
PORTVERSION=	${NSS_LDAP_VERSION}
CATEGORIES=	net linux
MASTER_SITES=	ftp://ftp.pbone.net/mirror/archive.fedoraproject.org/fedora/linux/updates/testing/10/i386/ \
		http://archives.fedoraproject.org/pub/archive/fedora/linux/updates/testing/10/i386/ \
		http://herveybayaustralia.com.au/ports/distfiles/
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${NSS_LDAP_VERSION}-${RPMVERSION}

MAINTAINER=	port_maintainer@herveybayaustralia.com.au
COMMENT=	RFC 2307 NSS Module (Linux Fedora 10)

#LICENSE=	GPLv2
#NO_LICENSES_INSTALL=yes	# license framework does not rm the "share" directory

NSS_LDAP_VERSION=264

USE_LINUX_RPM=	yes
USE_LINUX_PREFIX=yes
LINUX_DIST_VER=	10
RPMVERSION=	6.fc10
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${NSS_LDAP_VERSION}

MANPREFIX=	${PREFIX}/usr/share
MANCOMPRESSED=	no
MAN5=		nss_ldap.5.gz

.if defined(WITH_PAM)
PLIST_SUB+=	PAM=""
MAN5+=		pam_ldap.5.gz
.else
PLIST_SUB+=	PAM="@comment "
.endif

PORTDOCS=*

NO_STAGE=	yes
pre-fetch:
.if !defined(WITH_PAM)
	@${ECHO_MSG} "Use WITH_PAM if you require more advanced ldap support in the linuxulator"
.endif

post-extract:
	@if [ -f ${WRKDIR}/etc/ldap.conf ]; then \
		${MV} ${WRKDIR}/etc/ldap.conf ${WRKDIR}/etc/ldap.conf.dist; \
	fi
.if !defined(WITH_PAM)
	@if [ -f ${WRKDIR}/lib/security/pam_ldap.so ]; then \
		${RM} -rf ${WRKDIR}/lib/; \
	fi
	@if [ -f ${WRKDIR}/usr/share/doc/nss_ldap-264/COPYING.pam_ldap ]; then \
		${RM} ${WRKDIR}/usr/share/doc/nss_ldap-264/*.pam*; \
		${RM} -rf ${WRKDIR}/usr/share/doc/nss_ldap-264/pam.d; \
	fi
	@if [ -f ${WRKDIR}/usr/share/man/man5/pam_ldap.5.gz ]; then \
		${RM} ${WRKDIR}/usr/share/man/man5/pam_ldap.5.gz; \
	fi
.else
.if defined(NOPORTDOCS)
	@if [ -d ${WRKDIR}/usr/share/doc/nss_ldap-264/pam.d ]; then \
		${RM} -rf ${WRKDIR}/usr/share/doc/nss_ldap-264/pam.d/; \
	fi
.endif
.endif

post-install:
	@${CAT} ${PKGMESSAGE};

.include <bsd.port.mk>
