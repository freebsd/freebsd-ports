# New ports collection makefile for:   port-maintenance-tools
# Date created:        3 April 2004
# Whom:                Mark Linimon <linimon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	port-maintenance-tools
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	linimon@FreeBSD.org
COMMENT=	"meta-port" for administrative tools to maintain ports

# note: portuprade is brought in by pkg_cutleaves
RUN_DEPENDS=	\
		${LOCALBASE}/bin/cvsup:${PORTSDIR}/net/cvsup-without-gui \
		${LOCALBASE}/bin/fastest_cvsup:${PORTSDIR}/sysutils/fastest_cvsup \
		${LOCALBASE}/sbin/pkg_cutleaves:${PORTSDIR}/sysutils/pkg_cutleaves \
		${LOCALBASE}/bin/pkg_tree:${PORTSDIR}/sysutils/pkg_tree \
		${LOCALBASE}/bin/porteasy:${PORTSDIR}/misc/porteasy \
		${LOCALBASE}/bin/portell:${PORTSDIR}/misc/portell \
		${LOCALBASE}/sbin/portdowngrade:${PORTSDIR}/sysutils/portdowngrade

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
