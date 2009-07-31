# ex:ts=8
# Ports collection makefile for:	gfslicer
# Date created:			Jan 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gfslicer
PORTVERSION=	1.5.4
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility to split and join files

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_AUTOTOOLS=	automake:14:env
USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gfslicer.1
MANCOMPRESSED=	yes

post-extract:
.for file in install-sh missing mkinstalldirs
	@${LN} -sf ${AUTOMAKE_DIR}/${file} ${WRKSRC}
.endfor
	@${RM} -f ${WRKSRC}/config.cache

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN1}.gz ${MANPREFIX}/man/man1

.include <bsd.port.mk>
