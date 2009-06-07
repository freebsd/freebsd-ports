# New ports collection makefile for:   dieharder
# Date created:        14 November 2008
# Whom:                bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	dieharder
PORTVERSION=	2.28.1
CATEGORIES=	math
MASTER_SITES=	http://www.phy.duke.edu/~rgb/General/dieharder/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bf1783@gmail.com
COMMENT=	A random number generator testsuite

LIB_DEPENDS=	gsl:${PORTSDIR}/math/gsl

USE_AUTOTOOLS=	aclocal:110 autoheader:262 libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
MAN1=		dieharder.1
MAN3=		libdieharder.3

run-autotools:
	@(cd ${WRKSRC}; ${SETENV} ${AUTOTOOLS_ENV} ${SH} ./autogen.sh)

.include <bsd.port.mk>
