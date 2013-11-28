# Created by: Dominic Fandrey <kamikaze@bsdforen.de>
# $FreeBSD$

PORTNAME=	automounter
PORTVERSION=	1.5
CATEGORIES=	sysutils
MASTER_SITES=	SF/bsdadminscripts/${PORTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Provides scripts to dynamically configure amd

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
NO_BUILD=	yes
PKGMESSAGE=	${WRKSRC}/../NOTES

plist: patch
		@(cd ${WRKSRC}; ./plist.sh > ${PLIST})

# Use "amd -S" to avoid a vm locking panic, the scope of which has not yet
# been determined. See kern/181590.
do-install:
		@(cd ${WRKSRC}; ./install.sh -destdir=${STAGEDIR} \
			-prefix=${PREFIX} -amd="/usr/sbin/amd -S")

.include <bsd.port.mk>
