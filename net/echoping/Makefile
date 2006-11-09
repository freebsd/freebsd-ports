# New ports collection makefile for:	echoping
# Date created:		13 April 1997
# Whom:			peter
#
# $FreeBSD$
#

PORTNAME=	echoping
PORTVERSION=	5.99.0
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.internatif.org/pub/unix/echoping/
MASTER_SITE_SUBDIR=		${PORTNAME}
DISTNAME=	echoping-6.0-BETA

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	A ping-like program that uses tcp and/or http

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		idn.16:${PORTSDIR}/dns/libidn

USE_OPENLDAP=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-http --enable-icp --enable-smtp --with-ssl \
		--enable-ttcp --enable-tos --with-libidn=${LOCALBASE}

MAN1=		echoping.1 echoping_dns.1 echoping_random.1 echoping_whois.1 echoping_ldap.1

.include <bsd.port.mk>
