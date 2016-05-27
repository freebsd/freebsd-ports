# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-pause
PORTREVISION=		1

COMMENT=		Pause incoming OpenSMTPD messages to reduce spam
MAINTAINER=		adamw@FreeBSD.org

PLIST_FILES=		libexec/opensmtpd/filter-pause \
			man/man8/filter-pause.8.gz

CONFIGURE_ARGS+=	--with-filter-pause

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
