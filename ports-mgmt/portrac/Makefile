# $FreeBSD$

PORTNAME=	portrac
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://e-soul.org/distfiles/ \
		http://home.e-soul.org/~mgp/distfiles/

MAINTAINER=	mgp@e-soul.org
COMMENT=	Simple GUI tool for tracking port updates

LICENSE=	BSD2CLAUSE

PLIST_FILES=	bin/portrac \
		share/portrac/portrac.png \
		share/portrac/up-to-date.png \
		share/portrac/updates-available.png

PLIST_DIRS=	share/portrac

USES=		qmake tar:bzip2
USE_QT4=	gui moc_build

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-PortChecker.cc

do-install:
		${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/portrac ${STAGEDIR}${PREFIX}/bin && \
		${MKDIR} ${STAGEDIR}${DATADIR} && \
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/*.png ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
