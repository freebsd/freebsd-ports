# New ports collection makefile for:	xpi-firegpg
# Date created:		2008-07-24
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	firegpg
PORTVERSION=	0.5.2
CATEGORIES=	www
MASTER_SITES=	http://getfiregpg.org/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	stable

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extension that acts as an assistant for using GPG

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

XPI_ID=	firegpg@firegpg.team
USE_XPI=	*firefox*

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
