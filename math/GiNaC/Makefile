# ex:ts=8
# New ports collection makefile for:	GiNaC
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GiNaC
PORTVERSION=	0.8.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/GiNaC/ \
		http://www.ginac.de/

MAINTAINER=	ijliao@FreeBSD.org

USE_BZIP2=	yes
LIB_DEPENDS=	cln.1:${PORTSDIR}/math/cln

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

USE_GMAKE=	yes
USE_NEWGCC=	yes

INSTALLS_SHLIB=	yes

MAN1=	ginsh.1 viewgar.1 ginac-config.1

.include <bsd.port.mk>
