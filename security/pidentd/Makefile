# New ports collection makefile for:	pidentd
# Date created:		19 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	pidentd
PORTVERSION=	3.0.16
CATEGORIES=	security ipv6
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex

PATCH_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/ \
		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	dinoex
PATCHFILES=	pidentd-${PORTVERSION}-ipv6-20040227.diff.gz
PATCH_DIST_STRIP=	-p0

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An RFC1413 identification server

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
MAN8=		identd.8 idecrypt.8
PLIST_FILES=	sbin/ibench sbin/identd sbin/idecrypt sbin/ikeygen

.if defined(WITH_DES)
USE_OPENSSL=	yes
CFLAGS+=	-DINCLUDE_CRYPT -DOPENSSL_DES_LIBDES_COMPATIBILITY
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto
.endif

post-extract:
	${CP} ${FILESDIR}/idecrypt.8 ${WRKSRC}/doc/idecrypt.8

post-patch:
	@${REINPLACE_CMD} \
		-e "s| /etc/identd.conf| ${PREFIX}/etc/identd.conf|" \
		-e "s| /etc/identd.key| ${PREFIX}/etc/identd.key|" \
		${WRKSRC}/doc/identd.8 ${WRKSRC}/doc/idecrypt.8

post-install:
	${INSTALL_MAN} -m 644 ${WRKSRC}/doc/idecrypt.8 ${MANPREFIX}/man/man8/

.include <bsd.port.mk>
