# New ports collection makefile for:	fluxbox-sid-pack
# Date created:         7 June 2004
# Whom:               	Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	fluxbox-sid-pack
PORTVERSION=	20031226
CATEGORIES=	x11-themes
MASTER_SITES=	http://fluxbox.org/download/themes/sid/
DISTNAME=	sidpack

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Sid themes pack for fluxbox

RUN_DEPENDS=	fluxbox:${PORTSDIR}/x11-wm/fluxbox-devel

USE_BZIP2=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
.for i in aleczapka_combination.tar.bz2 aleczapka_digitalshe.tar.bz2 \
	aleczapka_fluxcarnation.tar.bz2 aleczapka_minime.tar.bz2 \
	aleczapka_posthuman.tar.bz2
	@${TAR} jxvf ${WRKDIR}/${i} -C ${PREFIX}/share/fluxbox/
.endfor

.include <bsd.port.mk>
