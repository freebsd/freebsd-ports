# $FreeBSD$

PORTNAME=	firstboot-pkgs
PORTVERSION=	1.4
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Install packages when the system first boots

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_INSTALL=	yes

USE_RC_SUBR=	firstboot_pkgs

.include <bsd.port.options.mk>

.if ${OSVERSION} < 902504 || ( ${OSVERSION} >= 1000000 && ${OSVERSION} < 1000100 ) || ( ${OSVERSION} >= 1000500 && ${OSVERSION} < 1000501 ) || (${OSVERSION} >= 1100000 && ${OSVERSION} < 1100001 )
IGNORE=	first boot rc.d scripts not supported on this version of FreeBSD
.endif

.include <bsd.port.mk>
