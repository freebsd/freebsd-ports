# New ports collection makefile for:	SSLtelnet
# Version required:	0.11
# Date created:		Mar 29, 1998
# Whom:			issei@t-cnet.or.jp
#
# $Id: Makefile,v 1.1.1.1 1998/04/11 15:07:05 vanilla Exp $

DISTNAME=		SSLtelnet-0.11
CATEGORIES=		net security
MASTER_SITES=		ftp://ftp.psy.uq.oz.au/pub/Crypto/SSLapps/

MAINTAINER=		issei@t-cnet.or.jp

BUILD_DEPENDS=		ssleay:${PORTSDIR}/security/SSLeay
RUN_DEPENDS=		ssleay:${PORTSDIR}/security/SSLeay

RESTRICTED=		"Cryptography"

.if !defined(BATCH)
INSTALL_TARGET=		install certificate
.endif

post-install:
	strip $(PREFIX)/bin/telnet
	strip $(PREFIX)/libexec/telnetd
.include <bsd.port.mk>
