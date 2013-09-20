# $FreeBSD$

PORTNAME=	port-maintenance-tools
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	ports-mgmt
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Meta-port for administrative tools to maintain ports

RUN_DEPENDS=	\
		${LOCALBASE}/sbin/portupgrade:${PORTSDIR}/ports-mgmt/portupgrade \
		${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion \
		${LOCALBASE}/sbin/pkg_cutleaves:${PORTSDIR}/ports-mgmt/pkg_cutleaves \
		${LOCALBASE}/bin/pkg_tree:${PORTSDIR}/ports-mgmt/pkg_tree \
		${LOCALBASE}/bin/porteasy:${PORTSDIR}/ports-mgmt/porteasy \
		${LOCALBASE}/bin/portell:${PORTSDIR}/ports-mgmt/portell \
		${LOCALBASE}/sbin/portdowngrade:${PORTSDIR}/ports-mgmt/portdowngrade

NO_BUILD=	yes

do-install:	# empty

NO_STAGE=	yes
.include <bsd.port.mk>
