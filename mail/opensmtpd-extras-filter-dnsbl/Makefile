# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-dnsbl
PORTREVISION=		0

COMMENT=		DNSBL-checking filter for OpenSMTPD
MAINTAINER=		adamw@FreeBSD.org

PLIST_FILES=		libexec/opensmtpd/filter-dnsbl \
			man/man8/filter-dnsbl.8.gz

CONFIGURE_ARGS+=	--with-filter-dnsbl

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
