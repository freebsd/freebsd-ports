# Created by: Brandon Fosdick <bfoz@bfoz.net>
# $FreeBSD$

PORTNAME=	mod_log_dbd
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	www databases
MASTER_SITES=	http://bfoz.net/projects/${PORTNAME}/release/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	bfoz@bfoz.net
COMMENT=	Uses APR DBD to store Apache access logs in a database


USE_APACHE=	22
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apache=${PREFIX}

do-install:
	${APXS} -i -a -n log_dbd ${WRKSRC}/mod_log_dbd.la

.include <bsd.port.mk>
