# New ports collection makefile for:    blas
# Date created:         27 October 1994
# Whom:                 ljo
#
# $FreeBSD$
#

PORTNAME=	blas
PORTVERSION=	1.0
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/blas/ \
		ftp://ftp.mirrorservice.org/sites/netlib.bell-labs.com/netlib/blas/ \
		http://www.netlib.org/blas/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Basic Linear Algebra, level 1, 2, and 3

INSTALLS_SHLIB=	yes
NO_WRKSUBDIR=	yes

do-configure:
	@${INSTALL_DATA} ${FILESDIR}/makefile.lib ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's+@FFLAGS@+${FFLAGS}+g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
