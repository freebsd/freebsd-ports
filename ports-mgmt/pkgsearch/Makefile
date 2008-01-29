# New ports collection makefile for:	pkgsearch
# Date created:				14 September 2007
# Whom:					Diego_Rocha <diegorocha1987@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pkgsearch
PORTVERSION=	1.0.5
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://dl.sharesource.org/${PORTNAME}/

MAINTAINER=	diegorocha1987@gmail.com
COMMENT=	Find your packages in ports and installed packages

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	boost_filesystem:${PORTSDIR}/devel/boost

WRKSRC=		${WRKDIR}/${DISTNAME}-build
PLIST_FILES=	sbin/pkgsearch etc/pkgsearch.conf

MAN1=		pkgsearch.1
MAN5=		pkgsearch.conf.5
MANCOMPRESSED=	yes

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|' \
		${WRKDIR}/${PORTNAME}-${PORTVERSION}/CMakeLists.txt

do-configure:
	@${CP} ${WRKDIR}/${DISTNAME}/pkgsearch.* ${WRKSRC}
	@cd ${WRKSRC}; \
		${LOCALBASE}/bin/cmake ${WRKDIR}/${DISTNAME}

post-build:
	@${GZIP_CMD} ${WRKDIR}/${DISTNAME}/pkgsearch.*

post-install:
	@${ECHO_CMD} "=================================================="
	@${ECHO_CMD} "             Important information"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "     After the instalation configure your"
	@${ECHO_CMD} "     pkgsearch.conf in ${PREFIX}/etc/pkgsearch"
	@${ECHO_CMD} "     to more information see pkgsearch.conf(5)"
	@${ECHO_CMD} "=================================================="

.include <bsd.port.mk>
