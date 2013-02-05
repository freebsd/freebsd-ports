# New ports collection makefile for:	openvas-libnasl
# Date created:		2008-04-27
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	openvas-libnasl
PORTVERSION=	2.0.1
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/561/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NASL libraries for OpenVAS

LIB_DEPENDS=	gcrypt.18:${PORTSDIR}/security/libgcrypt \
		gnutls.26:${PORTSDIR}/security/gnutls \
		gpg-error.0:${PORTSDIR}/security/libgpg-error \
		gpgme.19:${PORTSDIR}/security/gpgme \
		openvas.2:${PORTSDIR}/security/openvas-libraries \
		openvas_hg.2:${PORTSDIR}/security/openvas-libraries \
		tasn1.4:${PORTSDIR}/security/libtasn1

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_ICONV=	yes
USE_BISON=	build

MAN1=		openvas-libnasl-config.1 openvas-nasl.1

.include "${.CURDIR}/../../security/openvas-libraries/Makefile.common"

LDFLAGS+=	-lgcrypt

.include <bsd.port.mk>
