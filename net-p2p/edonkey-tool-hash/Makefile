# New ports collection makefile for:	edonkey hash tool
# Date created:				Wed Feb 20 18:03:49 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.3.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ed2k-tools
PKGNAMESUFFIX=	-tool-hash
DISTNAME=	ed2k_hash-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Both calculates 'eDonkey/Overnet hashes' producing ed2k:// file links

PLIST_FILES=	bin/edonkey-tool-hash
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
USE_SIZE=	yes
GNU_CONFIGURE=	yes

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
