# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-dkim
PORTREVISION=		0

COMMENT=		DKIM-signing filter for OpenSMTPD

PLIST_FILES=		libexec/opensmtpd/filter-dkim-signer \
			man/man8/filter-dkim-signer.8.gz

CONFIGURE_ARGS+=	--with-experimental-filter-dkim-signer

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
