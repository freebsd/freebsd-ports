# New ports collection makefile for:	libhome
# Date created:				Fri Aug 14 2003
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	libhome
PORTVERSION=	0.7
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pll

MAINTAINER=	kiwi@oav.net
COMMENT=	Libhome is a library providing a getpwname() emulation

LIB_DEPENDS+=	ldap:${PORTSDIR}/net/openldap21-client \
		mysqlclient:${PORTSDIR}/databases/mysql323-client

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--without-db3 --without-db4 --with-ldap --with-mysql

MAN5=		home.conf.5

.include <bsd.port.mk>
