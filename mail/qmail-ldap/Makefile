# New ports collection makefile for:	qmail-ldap
# Date created:				21 May 2000
# Whom:					Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION= 	${QMAIL_VERSION}.${LDAP_PATCH_DATE}
CATEGORIES=	mail
PKGNAMESUFFIX=	-ldap

PATCH_SITES=	http://www.nrg4u.com/qmail/
PATCHFILES=	qmail-ldap-1.03-${LDAP_PATCH_DATE}.patch.gz

MAINTAINER=	lioux@linf.unb.br

LIB_DEPENDS+=	ldap.1:${PORTSDIR}/net/openldap

.if !defined(PRE_MK_INCLUDED)
.include <bsd.port.pre.mk>
.endif

#PREFIX=		/var/qmail-ldap

DOCFILES+=	${WRKSRC}/QLDAPINSTALL ${WRKSRC}/QLDAPNEWS \
		${WRKSRC}/QLDAPTODO ${WRKSRC}/QLDAPPICTURE \
		${WRKSRC}/ANTISPAM

LDAP_PATCH_DATE=	20000701

# Local overrides
MASTERDIR=	${PORTSDIR}/mail/qmail
#MASTERDIR=	${.CURDIR}/../qmail
PATCHDIR=	${.CURDIR}/patches
PKGDIR_LOCAL=	${.CURDIR}/pkg
DESCR=		${PKGDIR_LOCAL}/DESCR
PLIST=		${PKGDIR_LOCAL}/PLIST
PKGMESSAGE=	${PKGDIR_LOCAL}/MESSAGE

PRE_MK_INCLUDED=	yes

.include "${MASTERDIR}/Makefile"
