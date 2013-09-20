# Created by: Anders Troback <freebsd@troback.com>
# $FreeBSD$

PORTNAME=	prelude-pflogger
DISTVERSION=	0.9.0-rc2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.com/download/releases/${PORTNAME}/

MAINTAINER=	freebsd@troback.com
COMMENT=	Prelude-PFlogger Listens at OpenBSD PF

LIB_DEPENDS+=	prelude:${PORTSDIR}/security/libprelude

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	prelude-pflogger

NO_STAGE=	yes
.include <bsd.port.mk>
