# New ports collection makefile for:	openvas-libraries
# Date created:		2008-04-26
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	openvas-libraries
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/419/

MAINTAINER=	cherry@trombik.org
COMMENT=	Libraries for OpenVAS

LIB_DEPENDS=	gnutls.26:${PORTSDIR}/security/gnutls

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		libopenvas-config.1

.include "${.CURDIR}/Makefile.common"

.include <bsd.port.mk>
