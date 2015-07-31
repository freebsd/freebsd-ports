# Created by: Philip M. Gollucci <pgollucci@p6m7g8.com>
# $FreeBSD$

PORTNAME=	freebsd-bugzilla-cli
PORTVERSION=	0.4.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	GH

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Interact with the FreeBSD bugzilla instance

LICENSE=	APACHE20

OPTIONS_GROUP=	BACKEND
OPTIONS_GROUP_BACKEND=	PYBUGZ
OPTIONS_SET=	PYBUGZ
OPTIONS_SUB=	yes

PYBUGZ_DESC=	use devel/pybugz for bugzilla interface
PYBUGZ_RUN_DEPENDS=	bugz:${PORTSDIR}/devel/pybugz

DATADIR=	${PREFIX}/share/bz

USE_GITHUB=	yes
GH_ACCOUNT=	pgollucci

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
