# $FreeBSD$

PORTNAME=	firstboot-freebsd-update
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Update the system using freebsd-update when it first boots

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_RC_SUBR=	firstboot_freebsd_update

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 1100001 )
IGNORE=	first boot rc.d scripts not supported on this version of FreeBSD
.endif

do-fetch do-install:
	@${DO_NADA}

.include <bsd.port.post.mk>
