# Created by: Niclas Zeising <zeising@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ostinato
PORTVERSION=	0.5.1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}${EXTRACTSUFFIX}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Packet crafter/generator and analyzer with friendly GUI

BUILD_DEPENDS=	protobuf>=2.3.0:${PORTSDIR}/devel/protobuf

USE_QT4=	gui moc_build qmake_build rcc_build uic_build network script \
		xml
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/drone \
		bin/ostinato

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

HAS_CONFIGURE=	yes

do-configure:
		@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

.include <bsd.port.mk>
