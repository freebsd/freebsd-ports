# New ports collection makefile for:	units
# Date created:		2001-11-03
# Whom:			Jason Harris <jharris@widomaker.com>
#
# $FreeBSD$
#

PORTNAME=	units
PORTVERSION=	2.00
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jharris@widomaker.com
COMMENT=	Unit conversion and calculation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

INFO=		units
MAN1=		gunits.1

post-patch:
	@${REINPLACE_CMD} -e \
	 's|$$(INSTALL_PROGRAM) units_cur|${INSTALL_SCRIPT} units_cur|' \
	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
