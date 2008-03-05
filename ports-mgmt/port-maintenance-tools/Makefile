# New ports collection makefile for:   port-maintenance-tools
# Date created:        3 April 2004
# Whom:                Mark Linimon <linimon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	port-maintenance-tools
PORTVERSION=	1.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	linimon@FreeBSD.org
COMMENT=	"meta-port" for administrative tools to maintain ports

RUN_DEPENDS=	\
		${LOCALBASE}/sbin/portupgrade:${PORTSDIR}/ports-mgmt/portupgrade \
		${LOCALBASE}/bin/fastest_cvsup:${PORTSDIR}/sysutils/fastest_cvsup \
		${LOCALBASE}/sbin/pkg_cutleaves:${PORTSDIR}/ports-mgmt/pkg_cutleaves \
		${LOCALBASE}/bin/pkg_tree:${PORTSDIR}/ports-mgmt/pkg_tree \
		${LOCALBASE}/bin/porteasy:${PORTSDIR}/ports-mgmt/porteasy \
		${LOCALBASE}/bin/portell:${PORTSDIR}/ports-mgmt/portell \
		${LOCALBASE}/sbin/portdowngrade:${PORTSDIR}/ports-mgmt/portdowngrade

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
