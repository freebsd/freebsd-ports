# New ports collection makefile for:   port-authoring-tools
# Date created:        3 April 2004
# Whom:                Mark Linimon <linimon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	port-authoring-tools
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	linimon@FreeBSD.org
COMMENT=	"meta-port" for tools to test and submit changes to ports

# note: portlint is brought in by porttools
RUN_DEPENDS=	\
		cvsup:${PORTSDIR}/net/cvsup-without-gui \
		fastest_cvsup:${PORTSDIR}/sysutils/fastest_cvsup \
		libchk:${PORTSDIR}/sysutils/libchk \
		port:${PORTSDIR}/devel/porttools

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
