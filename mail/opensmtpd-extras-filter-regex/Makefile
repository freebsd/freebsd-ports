# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-regex
PORTREVISION=		0

COMMENT=		Regular expression filter for OpenSMTPD

IGNORE=			temporary unavailable

CONFIGURE_ARGS+=	--with-experimental-filter-regex

PLIST=			${.CURDIR}/pkg-plist
MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail
	${INSTALL_DATA} ${WRKSRC}/extras/filters/filter-regex/filter-regex.conf \
		${STAGEDIR}${PREFIX}/etc/mail/filter-regex.conf.sample

.include "${MASTERDIR}/Makefile"
