# ex:ts=8
# Ports collection makefile for:	gfslicer
# Date created:			Jan 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gfslicer
PORTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.geocities.com/gfslicer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility to split and join files

BUILD_DEPENDS=	${LOCALBASE}/share/automake14/install-sh:${PORTSDIR}/devel/automake14

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomelibs gnomeprefix gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		gfslicer.1
MANCOMPRESSED=	yes

post-extract:
.for file in install-sh missing mkinstalldirs
	@${LN} -sf ${LOCALBASE}/share/automake14/${file} ${WRKSRC}
.endfor
	@${RM} -f ${WRKSRC}/config.cache

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|$$(top_builddir)/intl/libintl.a| -lintl|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-I$$(top_srcdir)/intl||g ; s|intl po|po|g ;'

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN1}.gz ${MANPREFIX}/man/man1

.include <bsd.port.mk>
