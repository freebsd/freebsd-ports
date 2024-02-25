PORTNAME=	ssldump
PORTVERSION=	0.9b3
PORTREVISION=	6
CATEGORIES=	net security
MASTER_SITES=	SF
PATCHFILES=	2-ssldump-tls12.diff
PATCH_SITES=	https://gist.githubusercontent.com/mtigas/5969597/raw/e62ea9ab8a66ad264ffac47c5047c8d7ba94a67f/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SSLv3/TLS network protocol analyzer
WWW=		https://sourceforge.net/projects/ssldump/

USES=	ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE} \
		--sbindir=${PREFIX}/bin

PLIST_FILES=	bin/ssldump share/man/man1/ssldump.1.gz

OPTIONS_DEFINE=	AES

AES_DESC=	Enable AES support from CVS (EXPERIMENTAL)

AES_EXTRA_PATCHES=	${FILESDIR}/extra-patch-aes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssldump ${STAGEDIR}${PREFIX}/bin/ssldump
	${INSTALL_MAN} ${WRKSRC}/ssldump.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
