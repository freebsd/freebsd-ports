# New ports collection makefile for:	SSLtelnet
# Date created:		Mar 29, 1998
# Whom:			issei@jp.FreeBSD.org
#
# $FreeBSD$

PORTNAME=		SSLtelnet
PORTVERSION=		0.13
PORTREVISION=		1
CATEGORIES=		net security
MASTER_SITES=		http://munitions2.xs4all.nl/software/network/ssl/applications/ \
			http://ftp.vc-graz.ac.at/mirror/crypto/ssl/SSLapps/ \
			http://munitions.hands.com/software/network/ssl/applications/ \
			http://munitions.ketelhot.de/software/network/ssl/applications/ \
			http://opensores.thebunker.net/pub/mirrors/SSLapps/ \
			${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kris

MAINTAINER=		ports@FreeBSD.org
COMMENT=	SSL enhanced telnet/telnetd

FORBIDDEN=	Known security issues
DEPRECATED=	${FORBIDDEN}
EXPIRATION_DATE=	2004-08-02

USE_OPENSSL=		YES

PLIST_SUB+=		OPENSSLDIR="${OPENSSLDIR}"

.if !defined(BATCH)
INSTALL_TARGET=		install certificate
.endif

# Make sure that whole directory tree exists.
pre-install:
	${MKDIR} ${OPENSSLDIR}/certs

post-install:
	${STRIP_CMD} ${PREFIX}/bin/telnet
	${STRIP_CMD} ${PREFIX}/libexec/telnetd

.include <bsd.port.mk>
