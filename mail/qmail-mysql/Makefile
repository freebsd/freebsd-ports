PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${MYSQL_PATCH_VERSION}
PORTREVISION=	3
CATEGORIES=	mail
PKGNAMESUFFIX=	-mysql

COMMENT=	Secure, reliable, and fast MTA for UNIX systems with MySQL support

CONFLICTS=	*qmail qmail-ldap qmail-spamcontrol *qmail-tls

MYSQL_PATCH_VERSION=	1.1.15

SLAVE_MYSQL=	yes

USES=		compiler:c11 mysql

MASTERDIR=	${.CURDIR}/../qmail
DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
