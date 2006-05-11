# New ports collection makefile for:	edonkey hash tool
# Date created:				Wed Feb 20 18:03:49 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.4.0
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ed2k-tools
PKGNAMESUFFIX=	-tool-hash
DISTNAME=	ed2k_hash-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Both calculates 'eDonkey/Overnet hashes' producing ed2k:// file links

PLIST_FILES=	bin/edonkey-tool-hash
GNU_CONFIGURE=	yes

WRKSRC=	${WRKDIR}/ed2k_hash-${PORTVERSION}

post-patch:
# respect CFLAGS
	@${REINPLACE_CMD} -E -e \
		's|-O2||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
# uphold POLA, do not change binary name
	@${INSTALL_PROGRAM} ${WRKSRC}/ed2k_hash/ed2k_hash \
		${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.mk>
