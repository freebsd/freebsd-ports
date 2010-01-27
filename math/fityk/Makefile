# ex:ts=8
# Ports collection makefile for:	fityk
# Date created:			Mar 8, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fityk
PORTVERSION=	0.9.0
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free peak fitting software

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_WX=		2.8+
WX_CONF_ARGS=	absolute
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-xylib --without-doc --disable-xyconvert
USE_LDCONFIG=	yes

MAN1=		fityk.1 xyconv.1
PORTDOCS=	*

CFLAGS+=	-D_GNU_SOURCE
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e '/HELP_DEF/s|pkgdatadir|docdir|g' \
		${WRKSRC}/src/wxgui/Makefile.in
	@${REINPLACE_CMD} -e '/XYLIB_USE_TR1_MEMORY/s| 1| 0|g' \
		${WRKSRC}/xylib/xylib/cache.h

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/fityk.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${DOCSDIR})
.endif
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
