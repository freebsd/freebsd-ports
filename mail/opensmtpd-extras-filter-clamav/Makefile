# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-clamav
PORTREVISION=		1

COMMENT=		Check messages with ClamAV in OpenSMTPD
MAINTAINER=		adamw@FreeBSD.org

RUN_DEPENDS=		clamscan:security/clamav

PLIST_FILES=		libexec/opensmtpd/filter-clamav \
			man/man8/filter-clamav.8.gz

CONFIGURE_ARGS+=	--with-filter-clamav

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
