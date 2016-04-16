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

# These have to be set at compile-time. These are the
# defaults for spamassassin.
FILTER_SPAMASSASSIN_HOST?=	127.0.0.1
FILTER_SPAMASSASSIN_PORT?=	783

post-patch:
	@${REINPLACE_CMD} \
		-e '/^#define SPAMASSASSIN_HOST/s/127.0.0.1/${FILTER_SPAMASSASSIN_HOST}/' \
		-e '/^#define SPAMASSASSIN_PORT/s/783/${FILTER_SPAMASSASSIN_PORT}/' \
		${WRKSRC}/extras/wip/filters/filter-spamassassin/filter_spamassassin.c
	@${REINPLACE_CMD} \
		-e 's/127.0.0.1/${FILTER_SPAMASSASSIN_HOST}/' \
		-e 's/783/${FILTER_SPAMASSASSIN_PORT}/' \
		${WRKSRC}/extras/wip/filters/filter-spamassassin/filter-spamassassin.8
		
.include "${MASTERDIR}/Makefile"
