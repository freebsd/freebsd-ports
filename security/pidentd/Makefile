# Created by: torstenb
# $FreeBSD$

PORTNAME=	pidentd
PORTVERSION=	3.0.19
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/unix/ident/servers/ \
		ftp://ftp.stack.nl/pub/users/johans/pidentd/

PATCH_SITES=	ftp://ftp.stack.nl/pub/users/johans/pidentd/ \
		ftp://mud.stack.nl/pub/pidentd/
PATCHFILES=	pidentd-${PORTVERSION}-ipv6-20080101.diff.gz
PATCH_DIST_STRIP=	-p0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RFC1413 identification server

BROKEN_FreeBSD_12=	fails to compile: k_freebsd2.c: storage size of 'pcbp' isn't known
BROKEN_FreeBSD_13=	fails to compile: k_freebsd2.c: storage size of 'pcbp' isn't known

CONFLICTS_INSTALL=	fakeident-[0-9]*

GNU_CONFIGURE=	yes
USES=		ssl

PLIST_FILES=	sbin/ibench sbin/identd sbin/idecrypt sbin/ikeygen \
		man/man8/identd.8.gz man/man8/idecrypt.8.gz

CFLAGS+=	-DINCLUDE_CRYPT -DOPENSSL_DES_LIBDES_COMPATIBILITY
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto

post-extract:
	${CP} ${FILESDIR}/idecrypt.8 ${WRKSRC}/doc/idecrypt.8

post-patch:
	@${REINPLACE_CMD} \
		-e 's| /etc/identd.conf| ${PREFIX}/etc/identd.conf|' \
		-e 's| /etc/identd.key| ${PREFIX}/etc/identd.key|' \
		${WRKSRC}/doc/identd.8 ${WRKSRC}/doc/idecrypt.8
	@${REINPLACE_CMD} -e 's|freebsd.4.7.|freebsd|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(sbindir)|$${DESTDIR}&|' \
		-e 's|-m 755|-s &|' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(mandir)|$${DESTDIR}&|' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} -m 644 ${WRKSRC}/doc/idecrypt.8 \
		${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
