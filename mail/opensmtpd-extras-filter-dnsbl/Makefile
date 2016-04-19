# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-dnsbl

COMMENT=		DNSBL-checking filter for OpenSMTPD
MAINTAINER=		adamw@FreeBSD.org

LIB_DEPENDS=		libasr.so:dns/libasr

PLIST_FILES=		libexec/opensmtpd/filter-dnsbl \
			man/man8/filter-dnsbl.8.gz

CONFIGURE_ARGS+=	--with-filter-dnsbl

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
