# Created by: fluffy
# $FreeBSD$

PKGNAMESUFFIX=		-filter-perl
PORTREVISION=		0

COMMENT=		Perl-script filter support for OpenSMTPD
MAINTAINER=		fluffy@FreeBSD.org

PLIST_FILES=		libexec/opensmtpd/filter-perl

CONFIGURE_ARGS+=	--with-filter-perl --with-perl-type=${perl_VERSION}

USES=			perl5

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
