# New ports collection makefile for:	Diego_Rocha
# Date created:				14 September 2007
# Whom:					Diego_Rocha
#
# $FreeBSD$
#

PORTNAME=	pkgsearch
PORTVERSION=	1.0.2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://dl.sharesource.org/${PORTNAME}/ \
		http://andsux.homeip.net/~diego/stable/

MAINTAINER=	diegorocha1987@gmail.com
COMMENT=	Find your packages in ports and installeds packages

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	boost_filesystem:${PORTSDIR}/devel/boost

USE_PGSQL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}-build
PLIST_FILES=	sbin/pkgsearch etc/pkgsearch/pkgsearch.conf

MAN1=		pkgsearch.1
MAN5=		pkgsearch.conf.5
MANCOMPRESSED=	yes

post-extract:
	${MKDIR} ${WRKSRC}

do-configure:
	@${CP} ${WRKDIR}/${DISTNAME}/pkgsearch.* ${WRKSRC}
	@cd ${WRKSRC}; \
		${LOCALBASE}/bin/cmake ${WRKDIR}/${DISTNAME}

post-build:
	@${GZIP_CMD} ${WRKDIR}/${DISTNAME}/pkgsearch.*

.include <bsd.port.mk>
