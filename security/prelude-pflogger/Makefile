# Created by: Anders Troback <freebsd@troback.com>
# $FreeBSD$

PORTNAME=	prelude-pflogger
DISTVERSION=	0.9.0-rc2
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.com/download/releases/${PORTNAME}/

MAINTAINER= ports@FreeBSD.org
COMMENT=	Prelude-PFlogger Listens at OpenBSD PF

LIB_DEPENDS+=	libprelude.so:${PORTSDIR}/security/libprelude

USES=		gmake
GNU_CONFIGURE=	yes
USE_RC_SUBR=	prelude-pflogger

NO_STAGE=	yes
.include <bsd.port.mk>
