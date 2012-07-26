# New ports collection makefile for:	openvas-libraries
# Date created:		2008-04-26
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	openvas-libraries
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/600/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libraries for OpenVAS

LIB_DEPENDS=	gnutls.47:${PORTSDIR}/security/gnutls \
		gcrypt.18:${PORTSDIR}/security/libgcrypt

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
USE_GNOME=	glib20
MAKE_JOBS_UNSAFE=	yes

MAN1=		libopenvas-config.1

.include "${.CURDIR}/Makefile.common"

.include <bsd.port.mk>
