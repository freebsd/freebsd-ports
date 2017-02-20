# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-pause
PORTREVISION=		2

COMMENT=		Pause incoming OpenSMTPD messages to reduce spam

PLIST_FILES=		libexec/opensmtpd/filter-pause \
			man/man8/filter-pause.8.gz

CONFIGURE_ARGS+=	--with-experimental-filter-pause

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
