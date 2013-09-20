# Created by: Dmirty Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagios-base-logos
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	SF/nagios/OldFiles
DISTNAME=	imagepak-base

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A collection of basic OS and device logos for Nagios

NO_BUILD=yes

NAGIOSWWWDIR?=		www/nagios
NAGIOS_LOGOS_DIR=	${PREFIX}/${NAGIOSWWWDIR}/images/logos

PLIST_SUB=	NAGIOSWWWDIR=${NAGIOSWWWDIR}

NO_STAGE=	yes
do-install:
	${MKDIR} ${NAGIOS_LOGOS_DIR}
	cd ${WRKDIR}/base && ${FIND} . | ${CPIO} -pdm \
		-R ${SHAREOWN}:${SHAREGRP} ${NAGIOS_LOGOS_DIR}

.include <bsd.port.mk>
