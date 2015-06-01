# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	openvas-libnasl
PORTVERSION=	2.0.1
PORTREVISION=	16
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/561/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NASL libraries for OpenVAS

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error \
		libgpgme.so:${PORTSDIR}/security/gpgme \
		libopenvas.so:${PORTSDIR}/security/openvas-libraries \
		libopenvas_hg.so:${PORTSDIR}/security/openvas-libraries \
		libtasn1.so:${PORTSDIR}/security/libtasn1

GNU_CONFIGURE=	yes
USES=		bison iconv libtool pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lgcrypt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/openvas-nasl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopenvasnasl.so

.include <bsd.port.mk>
