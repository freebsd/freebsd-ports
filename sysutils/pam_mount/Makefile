# Created by: gahr
# $FreeBSD$

PORTNAME=	pam_mount
PORTVERSION=	2.12
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME:S/_/-/}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PAM module that can mount volumes for a user session

LICENSE=	LGPL21 GPLv2
LICENSE_COMB=	multi

LIB_DEPENDS=	libHX.so:lang/libhx

USES=		gnome libtool perl5 pkgconfig ssl tar:xz
USE_GNOME=	libxml2

INSTALL_TARGET=	install-strip

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	libcrypto_LIBS="-L/usr/lib -lcrypto" \
		libcrypto_CFLAGS="-I/usr/include"
CONFIGURE_ARGS+=--localstatedir=/var \
		--without-cryptsetup \
		--with-ssbindir=${PREFIX}/sbin

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	variable has incomplete type 'EVP_CIPHER_CTX' (aka 'struct evp_cipher_ctx_st')
BROKEN_FreeBSD_13=	variable has incomplete type 'EVP_CIPHER_CTX' (aka 'struct evp_cipher_ctx_st')
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/pam_mount.c
	${REINPLACE_CMD} -e '/dist_security_DATA/s|\.xml$$|.xml.sample|' \
	   ${WRKSRC}/config/Makefile.am ${WRKSRC}/config/Makefile.in
	${MV} ${WRKSRC}/config/pam_mount.conf.xml ${WRKSRC}/config/pam_mount.conf.xml.sample
	${FIND} ${WRKSRC} -name "*.c" -exec ${REINPLACE_CMD} -e 's|HXformat2_aprintf|HXformat_aprintf|g' {} \;

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/xml/pam_mount/dtd
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/xml/pam_mount/

.include <bsd.port.post.mk>
