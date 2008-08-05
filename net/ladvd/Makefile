# New ports collection makefile for:	ladvd
# Date Created:				27 Jul 2008
# Whom:					sten@blinkenlights.nl
#
# $FreeBSD$
#

PORTNAME=	ladvd
PORTVERSION=	0.6.0
CATEGORIES=	net
MASTER_SITES=	http://blinkenlights.nl/software/ladvd/

MAINTAINER=	sten@blinkenlights.nl
COMMENT=	A minimal CDP/LLDP sender

GNU_CONFIGURE=	yes

MAN8=		ladvd.8
USE_RC_SUBR+=	ladvd
SUB_FILES=	pkg-message pkg-install

.if defined(NOPORTDOCS)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-Makefile.in
.endif

post-install:
	@${ECHO} "==>  Creating custom user to run pdns_recursor..."
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
