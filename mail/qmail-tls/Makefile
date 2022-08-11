PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${TLS_PATCH_DATE}
PORTREVISION=	4
CATEGORIES=	mail
PKGNAMESUFFIX=	-tls

COMMENT=	Secure, reliable, and fast MTA for UNIX systems with TLS support

CONFLICTS=	*qmail qmail-ldap *qmail-mysql qmail-spamcontrol

SLAVE_TLS=	yes

TLS_PATCH_DATE=	20200107

USES=		ssl

# Local overrides
MASTERDIR=	${.CURDIR}/../qmail
DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
