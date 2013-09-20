# Created by: torstenb
# $FreeBSD$

PORTNAME=	pidentd
PORTVERSION=	3.0.19
PORTREVISION=	2
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/ident/servers/ \
		ftp://ftp.stack.nl/pub/users/johans/pidentd/

PATCH_SITES=	ftp://ftp.stack.nl/pub/users/johans/pidentd/ \
		ftp://mud.stack.nl/pub/pidentd/
PATCHFILES=	pidentd-${PORTVERSION}-ipv6-20080101.diff.gz
PATCH_DIST_STRIP=	-p0

MAINTAINER=	johans@FreeBSD.org
COMMENT=	An RFC1413 identification server

CONFLICTS_INSTALL=	fakeident-[0-9]*

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

MAN8=		identd.8 idecrypt.8
PLIST_FILES=	sbin/ibench sbin/identd sbin/idecrypt sbin/ikeygen

CFLAGS+=	-DINCLUDE_CRYPT -DOPENSSL_DES_LIBDES_COMPATIBILITY
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto

NO_STAGE=	yes
post-extract:
	${CP} ${FILESDIR}/idecrypt.8 ${WRKSRC}/doc/idecrypt.8

post-patch:
	@${REINPLACE_CMD} \
		-e "s| /etc/identd.conf| ${PREFIX}/etc/identd.conf|" \
		-e "s| /etc/identd.key| ${PREFIX}/etc/identd.key|" \
		${WRKSRC}/doc/identd.8 ${WRKSRC}/doc/idecrypt.8
	@${REINPLACE_CMD} -e "s|freebsd.4.7.|freebsd|" ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} -m 644 ${WRKSRC}/doc/idecrypt.8 ${MANPREFIX}/man/man8

.include <bsd.port.mk>
