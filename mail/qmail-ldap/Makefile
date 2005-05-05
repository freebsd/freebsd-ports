# New ports collection makefile for:	qmail-ldap
# Date created:				21 May 2000
# Whom:					Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${LDAP_PATCH_DATE}
PORTREVISION=	2
CATEGORIES=	mail
PKGNAMESUFFIX=	-ldap

PATCH_SITES=	http://www.nrg4u.com/qmail/:ldap
PATCHFILES=	qmail-ldap-1.03-${LDAP_PATCH_DATE}.patch.gz:ldap

MAINTAINER=	freebsd@galle.com.br
COMMENT=	A SECURE, reliable, and FAST MTA for UNIX systems WITH LDAP support

EXTRA_PATCHES+=	${QMAIL_PORT_PATCHDIR}/patch-ab ${QMAIL_PORT_PATCHDIR}/patch-ac
PATCH_DIST_STRIP+=	-p1

CONFLICTS=	nss-[0-9]* emboss-[0-9]* digest-[0-9]*

USE_OPENLDAP=	yes
USE_REINPLACE=	yes
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}2

.if !defined(WITHOUT_TLS)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-with_tls
USE_OPENSSL=	yes
.endif # WITHOUT_TLS

# Patches from the main qmail port are not wanted
MAIN_QMAIL_PORT_DNS_PATCH_BARRIER=			yes
MAIN_QMAIL_PORT_WITH_BIG_CONCURRENCY_PATCH_BARRIER=	yes
MAIN_QMAIL_PORT_WITH_OUTGOINGIP_PATCH_BARRIER=		yes
MAIN_QMAIL_PORT_RFC2821_PATCH_BARRIER=			yes

LDAP_PATCH_DATE=	20020901

# Using default from master port, i.e., /var/qmail
PREFIX?=	${QMAIL_PORT_PREFIX}

.if !defined(_PREMKINCLUDED)
.include <bsd.port.pre.mk>
.endif

# Local overrides
MASTERDIR=	${.CURDIR}/../qmail
PATCHDIR=	${.CURDIR}/files
PKGDIR_LOCAL=	${.CURDIR}
DESCR=		${PKGDIR_LOCAL}/pkg-descr
PKGMESSAGE=	${PKGDIR_LOCAL}/pkg-message
PLIST=		${PKGDIR_LOCAL}/pkg-plist

QMAIL_TLS_PORT=	${.CURDIR}/../qmail-tls
QMAIL_PORT_PREFIX!=	cd ${MASTERDIR} && ${MAKE} -V PREFIX
QMAIL_PORT_PATCHDIR!=	cd ${MASTERDIR} && ${MAKE} -V PATCHDIR

DOCFILES+=	${WRKSRC}/QLDAPINSTALL ${WRKSRC}/QLDAPNEWS \
		${WRKSRC}/POPBEFORESMTP \
		${WRKSRC}/QLDAPTODO ${WRKSRC}/QLDAPPICTURE

slaveport-pre-fetch: qmail-ldap-pre-fetch

qmail-ldap-pre-fetch:
	@${ECHO_MSG} "WITHOUT_TLS=yes			disable SMTP TLS support"
	@${ECHO_MSG} "WITHOUT_LDAP_CLUSTER=yes		disable cluster support"
	@${ECHO_MSG} "WITHOUT_AUTOMAILDIRMAKE=yes	disable the auto-maildir-make feature"
	@${ECHO_MSG} "WITHOUT_AUTOHOMEDIRMAKE=yes	disable the auto-homedir-make feature"
	@${ECHO_MSG} "WITH_LDAP_DEBUG=yes		enable the possibility to log and"
	@${ECHO_MSG} "				debug imap and pop"
	@${ECHO_MSG} "WITH_CLEARTEXTPASSWD=yes	use cleartext passwords"
	@${ECHO_MSG} "WITH_DASH_EXT=yes		enable dash_ext extended mail addresses"
	@${ECHO_MSG} "				add"

slaveport-post-patch: qmail-ldap-post-patch

qmail-ldap-post-patch:
	@${REINPLACE_CMD} "s|LDAPLIBS=-L/usr/local/lib|LDAPLIBS=-L${LOCALBASE}/lib|;s|LDAPINCLUDES=-I/usr/local/include|LDAPINCLUDES=-I${LOCALBASE}/include|" ${WRKSRC}/Makefile
.if !defined(WITHOUT_TLS)
	@${REINPLACE_CMD} "s|#TLSON=|TLSON=|; \
		s|#TLSINCLUDES=-I/usr/local/include|TLSINCLUDES=-I${OPENSSLBASE}/include|; \
		s|#TLSLIBS=-L/usr/local/lib|TLSLIBS=-L${OPENSSLBASE}/lib|; \
		s|#OPENSSLBIN=/usr/local/bin/openssl|OPENSSLBIN=${OPENSSLBASE}/bin/openssl|" \
			${WRKSRC}/Makefile
.endif # !WITHOUT_TLS
.if !defined(WITHOUT_LDAP_CLUSTER)
	@${REINPLACE_CMD} "s|#LDAPFLAGS=-DQLDAP_CLUSTER\s+-DEXTERNAL_TODO|LDAPFLAGS\+=-DQLDAP_CLUSTER -DEXTERNAL_TODO#|" ${WRKSRC}/Makefile
.endif # WITHOUT_LDAP_CLUSTER
.if !defined(WITHOUT_AUTOMAILDIRMAKE)
	@${REINPLACE_CMD} "s|#MDIRMAKE=-DAUTOMAILDIRMAKE|MDIRMAKE=-DAUTOMAILDIRMAKE|" ${WRKSRC}/Makefile
.endif # WITHOUT_AUTOMAILDIRMAKE
.if !defined(WITHOUT_AUTOHOMEDIRMAKE)
	@${REINPLACE_CMD} "s|#HDIRMAKE=-DAUTOHOMEDIRMAKE|HDIRMAKE=-DAUTOHOMEDIRMAKE|" ${WRKSRC}/Makefile
.endif # WITHOUT_AUTOHOMEDIRMAKE
.if defined(WITH_LDAP_DEBUG)
	@${REINPLACE_CMD} "s|#DEBUG=-DDEBUG|DEBUG=-DDEBUG|" ${WRKSRC}/Makefile
.endif # WITH_LDAP_DEBUG
.if defined(WITH_CLEARTEXTPASSWD)
	@${REINPLACE_CMD} "s|^#\s*-DCLEARTEXTPASSWD.*$$|LDAPFLAGS\+=-DCLEARTEXTPASSWD|" \
		${WRKSRC}/Makefile
.endif # WITH_CLEARTEXTPASSWD
.if defined(WITH_DASH_EXT)
	@${REINPLACE_CMD} "s|^# -DDASH_EXT.*$$|LDAPFLAGS\+=-DDASH_EXT|" \
		${WRKSRC}/Makefile
.endif # WITH_DASH_EXT

certificate:
	@cd ${QMAIL_TLS_PORT} && ${MAKE} $@ clean

certificate-req:
	@cd ${QMAIL_TLS_PORT} && ${MAKE} $@ clean

.include "${MASTERDIR}/Makefile"
