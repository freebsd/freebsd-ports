# ports collection makefile for:        mktool
# Date created:                         2002/05/28
# Whom:                                 Jos Backus <jos@catnook.com>
#
# $FreeBSD$
#

PORTNAME=	mktool
PORTVERSION=	0.0.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.io.com/~manoj/file/

MAINTAINER=	jos@catnook.com

WRKSRC=		${WRKDIR}/mktool

USE_GMAKE=	yes
USE_REINPLACE=	yes

post-extract:
	@${REINPLACE_CMD} -e ' \
		s,^OPT=.*,OPT=${CFLAGS},; \
		s,=gcc,?=gcc,; \
		s,^bindir=.*,bindir=${PREFIX}/bin,; \
		s,cp -a,install -m ${BINMODE},' ${WRKSRC}/Makefile

.include <bsd.port.mk>
