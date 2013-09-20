# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sbniconfig
PORTVERSION=	1.0
CATEGORIES=	sysutils
DISTFILES=	# none

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Configurator for Granch SBNI12-xx adapters

NO_WRKSUBDIR=	yes
NO_PACKAGE=	"Depends on kernel"
ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/sbniconfig

NO_STAGE=	yes
post-extract:
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/sbniconfig.c ${WRKDIR}

.include <bsd.port.mk>
