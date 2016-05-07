# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-filter-clamav

COMMENT=		Check messages with ClamAV in OpenSMTPD
MAINTAINER=		adamw@FreeBSD.org

RUN_DEPENDS=		clamscan:security/clamav

PLIST_FILES=		libexec/opensmtpd/filter-clamav \
			man/man8/filter-clamav.8.gz

CONFIGURE_ARGS+=	--with-filter-clamav

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

# These have to be set at compile-time. These are the
# defaults for ClamAV.
FILTER_CLAMAV_HOST?=	127.0.0.1
FILTER_CLAMAV_PORT?=	3310

post-patch:
	@${REINPLACE_CMD} \
		-e '/^#define CLAMAV_HOST/s/127.0.0.1/${FILTER_CLAMAV_HOST}/' \
		-e '/^#define CLAMAV_PORT/s/783/${FILTER_CLAMAV_PORT}/' \
		${WRKSRC}/extras/wip/filters/filter-clamav/filter_clamav.c
	@${REINPLACE_CMD} \
		-e 's/127.0.0.1/${FILTER_CLAMAV_HOST}/' \
		-e 's/783/${FILTER_CLAMAV_PORT}/' \
		${WRKSRC}/extras/wip/filters/filter-clamav/filter-clamav.8
		
.include "${MASTERDIR}/Makefile"
