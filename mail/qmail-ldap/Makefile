# New ports collection makefile for:	qmail-ldap
# Date created:				21 May 2000
# Whom:					Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${LDAP_PATCH_DATE}
CATEGORIES=	mail
PKGNAMESUFFIX=	-ldap

PATCH_SITES=	http://www.nrg4u.com/qmail/
PATCHFILES=	qmail-ldap-1.03-${LDAP_PATCH_DATE}.patch.gz
PATCH_DIST_STRIP+=	-p1

EXTRA_PATCHES+=	${QMAIL_PORT_PATCHDIR}/patch-ab ${QMAIL_PORT_PATCHDIR}/patch-ac

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS+=	ldap.1:${PORTSDIR}/net/openldap

# Patches from the main qmail port are not wanted
MAIN_QMAIL_PORT_PATCH_BARRIER=	yes

LDAP_PATCH_DATE=	20010201

# Using default from master port, i.e., /var/qmail
PREFIX?=	${QMAIL_PORT_PREFIX}
#PREFIX=		/var/qmail-ldap

.if !defined(PRE_MK_INCLUDED)
.include <bsd.port.pre.mk>
.endif

#QMAIL_PORT=	${PORTSDIR}/mail/qmail
QMAIL_PORT=	${.CURDIR}/../qmail
QMAIL_PORT_PREFIX!=	cd ${QMAIL_PORT} && ${MAKE} -V PREFIX
QMAIL_PORT_PATCHDIR!=	cd ${QMAIL_PORT} && ${MAKE} -V PATCHDIR

DOCFILES+=	${WRKSRC}/QLDAPINSTALL ${WRKSRC}/QLDAPNEWS \
		${WRKSRC}/QLDAPTODO ${WRKSRC}/QLDAPPICTURE \
		${WRKSRC}/ANTISPAM

yetanotherone-pre-fetch: ldap-pre-fetch

ldap-pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_LDAP_CLUSTER=yes	enable cluster support"
	@${ECHO_MSG} "WITH_AUTOMAILDIRMAKE=yes	enable the auto-maildir-make feature"
	@${ECHO_MSG} "WITH_AUTOHOMEDIRMAKE=yes	enable the auto-homedir-make feature"
	@${ECHO_MSG} "WITH_LDAP_DEBUG=yes	enable the possibility to log and"
	@${ECHO_MSG} "				debug imap and pop"
	@${ECHO_MSG} "WITH_CLEARTEXTPASSWD=yes	use cleartext passwords"
	@${ECHO_MSG} ""

yetanotherone-post-patch: ldap-post-patch

ldap-post-patch:
.if defined(WITH_LDAP_CLUSTER)
	@${PERL} -pi -ne "s|#LDAPFLAGS=-DQLDAP_CLUSTER|LDAPFLAGS\+=-DQLDAP_CLUSTER|" ${WRKSRC}/Makefile
.endif # WITH_LDAP_CLUSTER
.if defined(WITH_AUTOMAILDIRMAKE)
	@${PERL} -pi -ne "s|#MDIRMAKE=-DAUTOMAILDIRMAKE|MDIRMAKE=-DAUTOMAILDIRMAKE|" ${WRKSRC}/Makefile
.endif # WITH_AUTOMAILDIRMAKE
.if defined(WITH_AUTOHOMEDIRMAKE)
	@${PERL} -pi -ne "s|#HDIRMAKE=-DAUTOHOMEDIRMAKE|HDIRMAKE=-DAUTOHOMEDIRMAKE|" ${WRKSRC}/Makefile
.endif # WITH_AUTOHOMEDIRMAKE
.if defined(WITH_LDAP_DEBUG)
	@${PERL} -pi -ne "s|#DEBUG=-DDEBUG|DEBUG=-DDEBUG|" ${WRKSRC}/Makefile
.endif # WITH_LDAP_DEBUG
.if defined(WITH_CLEARTEXTPASSWD)
	@${PERL} -pi -ne "s|# -DCLEARTEXTPASSWD to the LDAPFLAGS|LDAPFLAGS\+=-DCLEARTEXTPASSWD|" \
		${WRKSRC}/Makefile
.endif # WITH_CLEARTEXTPASSWD

# Local overrides
MASTERDIR=	${QMAIL_PORT}
PATCHDIR=	${.CURDIR}/files
PKGDIR_LOCAL=	${.CURDIR}
COMMENT=	${PKGDIR_LOCAL}/pkg-comment
DESCR=		${PKGDIR_LOCAL}/pkg-descr
PKGMESSAGE=	${PKGDIR_LOCAL}/pkg-message
PLIST=		${PKGDIR_LOCAL}/pkg-plist

PRE_MK_INCLUDED=	yes

.include "${MASTERDIR}/Makefile"
