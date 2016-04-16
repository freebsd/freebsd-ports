# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-dkim

COMMENT=		DKIM-signing filter for OpenSMTPD
MAINTAINER=		adamw@FreeBSD.org

PLIST_FILES=		libexec/opensmtpd/filter-dkim-signer \
			man/man8/filter-dkim-signer.8.gz

CONFIGURE_ARGS+=	--with-filter-dkim-signer

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
