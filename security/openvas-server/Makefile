# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	openvas-server
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/593/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Security scanner: a fork of Nessus

LIB_DEPENDS=	libopenvas.so:${PORTSDIR}/security/openvas-libraries \
		libopenvasnasl.so:${PORTSDIR}/security/openvas-libnasl

GNU_CONFIGURE=	yes
USES=		gettext pkgconfig
USE_RC_SUBR=	openvasd

.include "${.CURDIR}/../../security/openvas-libraries/Makefile.common"

LDFLAGS+=	-lgcrypt

.include <bsd.port.mk>
