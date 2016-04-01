# Created by: Mario S F Ferreira <lioux@linf.unb.br>
# $FreeBSD$

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${LDAP_PATCH_DATE}
PORTREVISION=	1
CATEGORIES=	mail
PKGNAMESUFFIX=	-ldap

COMMENT=	Secure, reliable, and fast MTA for UNIX systems with LDAP support

RUN_DEPENDS=	${LOCALBASE}/bin/svscan:sysutils/daemontools \
		${LOCALBASE}/bin/tcprules:sysutils/ucspi-tcp

CONFLICTS=	emboss-[0-9]* digest-[0-9]* *qmail-[0-9]* *qmail-mysql-[0-9]* \
		qmail-spamcontrol-[0-9]* *qmail-tls-[0-9]*

EXTRA_PATCHES+=	${MASTERDIR}/files/patch-Makefile \
		${MASTERDIR}/files/patch-auto_uids-c-dist

USE_OPENLDAP=	yes
SLAVE_LDAP=	yes

LDAP_PATCH_DATE=	20120221

MASTERDIR=	${.CURDIR}/../qmail
DESCR=		${.CURDIR}/pkg-descr
PATCHDIR=	${.CURDIR}/files

.include "${MASTERDIR}/Makefile"
