PORTNAME=	freebsd-bugzilla-cli
PORTVERSION=	0.15.1
CATEGORIES=	ports-mgmt

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Interact with the FreeBSD bugzilla instance
WWW=		https://github.com/pgollucci/freebsd-bugzilla-cli

DEPRECATED=	Broken. Upstream unavailable.
EXPIRATION_DATE=	2024-11-01

LICENSE=	APACHE20

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

OPTIONS_GROUP=	BACKEND
OPTIONS_GROUP_BACKEND=	PYBUGZ
OPTIONS_DEFAULT=	PYBUGZ
OPTIONS_SUB=	yes

PYBUGZ_DESC=	use devel/pybugz for bugzilla interface
PYBUGZ_RUN_DEPENDS=	bugz:devel/pybugz

DATADIR=	${PREFIX}/share/bz

USE_GITHUB=	yes
GH_ACCOUNT=	pgollucci

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
