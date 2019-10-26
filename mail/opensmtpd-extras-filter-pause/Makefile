# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-pause
PORTREVISION=		-0

COMMENT=		Pause incoming OpenSMTPD messages to reduce spam

IGNORE=			temporary unavailable

PLIST_FILES=		libexec/opensmtpd/filter-pause \
			man/man8/filter-pause.8.gz

CONFIGURE_ARGS+=	--with-experimental-filter-pause

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
