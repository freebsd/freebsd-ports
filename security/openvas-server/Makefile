# New ports collection makefile for:	openvas-server
# Date created:		2008-04-26
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	openvas-server
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/407/

MAINTAINER=	cherry@trombik.org
COMMENT=	A security scanner: a fork of Nessus

LIB_DEPENDS=	openvas.1:${PORTSDIR}/security/openvas-libraries \
		openvasnasl.1:${PORTSDIR}/security/openvas-libnasl

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
GNU_CONFIGURE=	yes
# XXX openvas-mkcert uses gettext
USE_GETTEXT=	yes
USE_RC_SUBR=	openvasd

MAN1=		openvas-check-signature.1 openvas-mkrand.1
MAN8=		openvasd.8 openvas-adduser.8 openvas-rmuser.8 openvas-mkcert.8

.include "${.CURDIR}/../../security/openvas-libraries/Makefile.common"

.include <bsd.port.mk>
