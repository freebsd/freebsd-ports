# New ports collection makefile for:	ssl-admin
# Date created:			21 July 2008
# Whom:				Eric Crist <ecrist@secure-computing.net>
#
# $FreeBSD$
#

PORTNAME=	ssl-admin
DISTVERSION=	1.0b1.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		ftp://ftp.secure-computing.net/pub/FreeBSD/ports/

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	OpenSSL certificate manager

RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/zip \
		zip:${PORTSDIR}/archivers/unzip

USE_PERL5_RUN=	YES
MAN1=		ssl-admin.1
MAN5=		ssl-admin.conf.5
SUB_FILES=	pkg-message

NO_PACKAGE=	This is a perl script - there is no reason to package it

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
