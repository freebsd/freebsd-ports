# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssldump
PORTVERSION=	0.9b3
PORTREVISION=	5
CATEGORIES=	net security
MASTER_SITES=	SF
PATCHFILES=	2-ssldump-tls12.diff
PATCH_SITES=	https://gist.githubusercontent.com/mtigas/5969597/raw/e62ea9ab8a66ad264ffac47c5047c8d7ba94a67f/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	SSLv3/TLS network protocol analyzer

USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE} \
		--sbindir=${PREFIX}/bin

OPTIONS_DEFINE=	AES
AES_DESC=	Enable AES support from CVS (EXPERIMENTAL)

PLIST_FILES=	bin/ssldump man/man1/ssldump.1.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAES}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-aes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssldump ${STAGEDIR}${PREFIX}/bin/ssldump
	${INSTALL_MAN} ${WRKSRC}/ssldump.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
