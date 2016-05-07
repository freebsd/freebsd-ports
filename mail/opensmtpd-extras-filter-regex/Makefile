# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-regex

COMMENT=		Regular expression filter for OpenSMTPD
MAINTAINER=		adamw@FreeBSD.org

CONFIGURE_ARGS+=	--with-filter-regex

PLIST=			${.CURDIR}/pkg-plist
MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|/etc/mail/filter-regex.conf|${PREFIX}&|' \
		${WRKSRC}/extras/wip/filters/filter-regex/filter_regex.c \
		${WRKSRC}/extras/wip/filters/filter-regex/filter-regex.8

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail
	${INSTALL_DATA} ${WRKSRC}/extras/wip/filters/filter-regex/filter-regex.conf \
		${STAGEDIR}${PREFIX}/etc/mail/filter-regex.conf.sample

.include "${MASTERDIR}/Makefile"
