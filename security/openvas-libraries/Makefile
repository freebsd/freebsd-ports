# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	openvas-libraries
PORTVERSION=	2.0.3
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/600/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries for OpenVAS

LIB_DEPENDS=	gnutls.26:${PORTSDIR}/security/gnutls \
		gcrypt:${PORTSDIR}/security/libgcrypt

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	glib20
MAKE_JOBS_UNSAFE=	yes

MAN1=		libopenvas-config.1

NO_STAGE=	yes
.include "${.CURDIR}/Makefile.common"

.include <bsd.port.mk>
