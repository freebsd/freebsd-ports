# ex:ts=8
# New ports collection makefile for:   cln
# Date created:                Fab 11, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cln
PORTVERSION=	1.1
CATEGORIES=	math devel
MASTER_SITES=	ftp://ftp.ilog.fr/pub/Users/haible/gnu/ \
		ftp://ftp.santafe.edu/pub/gnu/ \
		ftp://ftpthep.physik.uni-mainz.de/pub/gnu/

MAINTAINER=	ijliao@FreeBSD.org

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/cln --infodir=${PREFIX}/info \
		--mandir=${PREFIX}/man

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

MAN1=		cln-config.1

.include <bsd.port.mk>
