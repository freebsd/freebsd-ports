# New ports collection makefile for:	SSLtelnet
# Version required:	0.13
# Date created:		Mar 29, 1998
# Whom:			issei@jp.FreeBSD.ORG
#
# $Id: Makefile,v 1.5 1998/10/19 15:49:06 vanilla Exp $

DISTNAME=		SSLtelnet-0.13
CATEGORIES=		net security
MASTER_SITES=		ftp://ftp.psy.uq.oz.au/pub/Crypto/SSLapps/

MAINTAINER=		issei@jp.FreeBSD.ORG

.if defined(USA_RESIDENT) && ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
pre-fetch:
	@echo
	@echo You must set variable USA_RESIDENT to YES, if you are USA resident
	@echo or to NO, if you aren\'t USA resident to build this package.
	@echo You must also have installed RSAREF if you are USA resident.
	@false
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES
LIB_DEPENDS=		rsaref.2:${PORTSDIR}/security/rsaref

pre-configure:
	${PATCH} ${PATCH_DIST_ARGS} < ${FILESDIR}/Makefile.patch
.endif
.endif

BUILD_DEPENDS=		ssleay:${PORTSDIR}/security/openssl
RUN_DEPENDS=		ssleay:${PORTSDIR}/security/openssl

RESTRICTED=		"Cryptography"

.if !defined(BATCH)
INSTALL_TARGET=		install certificate
.endif

post-install:
	strip $(PREFIX)/bin/telnet
	strip $(PREFIX)/libexec/telnetd

.include <bsd.port.mk>
