# New ports collection makefile for:	SSLtelnet
# Date created:		Mar 29, 1998
# Whom:			issei@jp.FreeBSD.org
#
# $FreeBSD$

PORTNAME=		SSLtelnet
PORTVERSION=		0.13
CATEGORIES=		net security
MASTER_SITES=		${MASTER_SITE_LOCAL} \
			ftp://ftp.psy.uq.oz.au/pub/Crypto/SSLapps/
MASTER_SITE_SUBDIR=	kris

MAINTAINER=		ports@FreeBSD.org

USE_OPENSSL=		YES

PLIST_SUB+=		OPENSSLDIR="${OPENSSLDIR}"

.if !defined(BATCH)
INSTALL_TARGET=		install certificate
.endif

# Make sure that whole directory tree exists.
pre-install:
	${MKDIR} ${OPENSSLDIR}/certs

post-install:
	strip $(PREFIX)/bin/telnet
	strip $(PREFIX)/libexec/telnetd

.include <bsd.port.mk>
