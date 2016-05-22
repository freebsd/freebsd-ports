# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-spamassassin

COMMENT=		Spamassassin filter addon for OpenSMTPD
MAINTAINER=		adamw@FreeBSD.org

PLIST_FILES=		libexec/opensmtpd/filter-spamassassin \
			man/man8/filter-spamassassin.8.gz

CONFIGURE_ARGS+=	--with-filter-spamassassin

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
