# New ports collection makefile for:	nagios-base-logos
# Date created:				4 April 2005
# Whom:					Dmirty Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios-base-logos
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=nagios
DISTNAME=	imagepak-base

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A collection of basic OS and device logos for Nagios

NO_BUILD=yes

NAGIOS_LOGOS_DIR=	${PREFIX}/share/nagios/images/logos

do-install:
	${MKDIR} ${NAGIOS_LOGOS_DIR}
	cd ${WRKDIR}/base && ${FIND} . | ${CPIO} -pdm \
		-R ${SHAREOWN}:${SHAREGRP} ${NAGIOS_LOGOS_DIR}

.include <bsd.port.mk>
