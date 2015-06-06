# $FreeBSD$

PORTNAME=	port-maintenance-tools
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	ports-mgmt

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Meta-port for administrative tools to maintain ports

USES=	metaport

RUN_DEPENDS=	\
		${LOCALBASE}/sbin/portupgrade:${PORTSDIR}/ports-mgmt/portupgrade \
		${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion \
		${LOCALBASE}/sbin/pkg_cutleaves:${PORTSDIR}/ports-mgmt/pkg_cutleaves \
		${LOCALBASE}/bin/pkg_tree:${PORTSDIR}/ports-mgmt/pkg_tree \
		${LOCALBASE}/sbin/portdowngrade:${PORTSDIR}/ports-mgmt/portdowngrade

.include <bsd.port.mk>
