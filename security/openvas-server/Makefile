# New ports collection makefile for:	openvas-server
# Date created:		2008-04-26
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	openvas-server
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/593/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A security scanner: a fork of Nessus

LIB_DEPENDS=	openvas.2:${PORTSDIR}/security/openvas-libraries \
		openvasnasl.2:${PORTSDIR}/security/openvas-libnasl

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_RC_SUBR=	openvasd

MAN1=		openvas-mkrand.1 openvas-mkcert-client.1 openvasd-config.1
MAN8=		openvasd.8 openvas-adduser.8 openvas-rmuser.8 openvas-mkcert.8

.include "${.CURDIR}/../../security/openvas-libraries/Makefile.common"

.include <bsd.port.mk>
