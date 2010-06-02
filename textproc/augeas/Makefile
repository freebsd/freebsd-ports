# Ports collection makefile for:  textproc/augeas
# Date created:			  19 May 2010
# Whom:				  Russell Jackson <raj@csub.edu>
#
# $FreeBSD$
#

PORTNAME=	augeas
PORTVERSION=	0.7.1
CATEGORIES=	textproc
MASTER_SITES=	http://augeas.net/download/

MAINTAINER=	raj@csub.edu
COMMENT=	A configuration editing tool

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262 aclocal:110 autoheader:262 automake:110 libtool:22
ACLOCAL_ARGS=	-I . -I gnulib/m4 -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes

MAN1=		augparse.1 augtool.1
MANCOMPRESSED=	no

LENSESDIR=	${PREFIX}/share/augeas/lenses

post-extract:
	@${RM} ${WRKSRC}/gnulib/lib/gettext.h

post-patch:
	@${REINPLACE_CMD} -e 's:$$(libdir)/pkgconfig:${PREFIX}/libdata/pkgconfig:' ${WRKSRC}/Makefile.am

post-install:
	${MKDIR} ${LENSESDIR}/tests
	${INSTALL_DATA} ${FILESDIR}/rcconf.aug ${LENSESDIR}/rcconf.aug
	${INSTALL_DATA} ${FILESDIR}/test_rcconf.aug ${LENSESDIR}/tests/rcconf.aug

.include <bsd.port.mk>
