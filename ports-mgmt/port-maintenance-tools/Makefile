# $FreeBSD$

PORTNAME=	port-maintenance-tools
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	ports-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Meta-port for administrative tools to maintain ports

USES=	metaport

RUN_DEPENDS=	\
		${LOCALBASE}/sbin/portupgrade:ports-mgmt/portupgrade \
		${LOCALBASE}/bin/svn:devel/subversion \
		${LOCALBASE}/sbin/pkg_cutleaves:ports-mgmt/pkg_cutleaves \
		${LOCALBASE}/bin/pkg_tree:ports-mgmt/pkg_tree \
		${LOCALBASE}/sbin/portdowngrade:ports-mgmt/portdowngrade

.include <bsd.port.mk>
