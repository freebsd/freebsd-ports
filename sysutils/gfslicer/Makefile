# ex:ts=8
# Ports collection makefile for:	gfslicer
# Date created:			Jan 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gfslicer
PORTVERSION=	1.5.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.geocities.com/gfslicer/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

MANCOMPRESSED=	yes
MAN1=	gfslicer.1

post-extract:
.for file in install-sh missing mkinstalldirs
	@${LN} -sf ${LOCALBASE}/share/automake/${file} ${WRKSRC}
.endfor
	@${RM} -f ${WRKSRC}/config.cache

post-patch:
	@${PERL} -pi -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

post-install:
	@${CP} ${WRKSRC}/${MAN1}.gz ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
