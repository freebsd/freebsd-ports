# New ports collection makefile for:	libhome
# Date created:				Fri Aug 14 2003
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	lmtpd
PORTVERSION=	0.9.8
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pll

MAINTAINER=	kiwi@oav.net
COMMENT=	LMTPD is a lmtp server compliant with RFC 2033 and Maildir++

LIB_DEPENDS=	mysqlclient:${PORTSDIR}/databases/mysql323-client \
		pcre:${PORTSDIR}/devel/pcre \
		iconv:${PORTSDIR}/converters/libiconv
BUILD_DEPENDS=	${LOCALBASE}/lib/libhome.a:${PORTSDIR}/misc/libhome

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-mysqllog --without-db3 --without-db4 --with-pcre --without-perl

MAN8=		lmtpd.8

.include <bsd.port.mk>
