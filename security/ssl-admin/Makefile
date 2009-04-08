# Ports collection makefile for:	ssl-admin
# Date created:			21 July 2008
# Whom:				Eric Crist <ecrist@secure-computing.net>
#
# $FreeBSD$
#

PORTNAME=	ssl-admin
DISTVERSION=	1.0.2
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.secure-computing.net/pub/FreeBSD/ports/ssl-admin/

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	OpenSSL certificate manager with OpenVPN support

RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/zip \
		zip:${PORTSDIR}/archivers/unzip

USE_PERL5_RUN=	YES
MAN1=		ssl-admin.1
MAN5=		ssl-admin.conf.5
SUB_FILES=	pkg-message

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
