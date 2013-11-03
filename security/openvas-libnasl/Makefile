# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	openvas-libnasl
PORTVERSION=	2.0.1
PORTREVISION=	10
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/561/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NASL libraries for OpenVAS

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error \
		libgpgme.so:${PORTSDIR}/security/gpgme \
		libopenvas.so.2:${PORTSDIR}/security/openvas-libraries \
		libopenvas_hg.so.2:${PORTSDIR}/security/openvas-libraries \
		libtasn1.so:${PORTSDIR}/security/libtasn1

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		bison iconv pkgconfig

MAN1=		openvas-libnasl-config.1 openvas-nasl.1

NO_STAGE=	yes
.include "${.CURDIR}/../../security/openvas-libraries/Makefile.common"

LDFLAGS+=	-lgcrypt

.include <bsd.port.mk>
