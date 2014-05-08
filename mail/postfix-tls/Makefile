# Created by: Bjoern A. Zeeb <bz@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-tls

CONFLICTS_INSTALL=	courier-0.* postfix-1.* postfix2?-* postfix21?-* \
			postfix-current-2.* postfix-current-base-2.* sendmail-8.* \
			sendmail+*-8.* smail-3.* zmailer-2.* opensmtpd-[0-9]* \
			postfix-2.*

OPTIONS_SLAVE=	TLS

MASTERDIR=	${.CURDIR}/../postfix
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

.include "${MASTERDIR}/Makefile"
