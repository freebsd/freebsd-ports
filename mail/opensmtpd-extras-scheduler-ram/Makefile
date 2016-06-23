# Created by: fluffy
# $FreeBSD$

PKGNAMESUFFIX=		-scheduler-ram
PORTREVISION=		0

COMMENT=		RAM scheduler support for OpenSMTPD

PLIST_FILES=		libexec/opensmtpd/scheduler-ram

CONFIGURE_ARGS+=	--with-scheduler-ram

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
