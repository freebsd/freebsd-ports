# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-spamassassin
PORTREVISION=		0

COMMENT=		Spamassassin filter addon for OpenSMTPD

IGNORE=			temporary unavailable

PLIST_FILES=		libexec/opensmtpd/filter-spamassassin \
			man/man8/filter-spamassassin.8.gz

CONFIGURE_ARGS+=	--with-experimental-filter-spamassassin

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
