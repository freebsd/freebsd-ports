# New ports collection makefile for:	openvas-libraries
# Date created:		2008-04-26
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	openvas-libraries
PORTVERSION=	2.0.3
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/600/

MAINTAINER=	cherry@trombik.org
COMMENT=	Libraries for OpenVAS

LIB_DEPENDS=	gnutls.40:${PORTSDIR}/security/gnutls

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	glib20 pkgconfig

MAN1=		libopenvas-config.1

.include "${.CURDIR}/Makefile.common"

.include <bsd.port.mk>
