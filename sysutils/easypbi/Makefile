#
# $FreeBSD$
#

PORTNAME=	easypbi
PORTVERSION=	2.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/makeapbi/${PORTNAME}/

MAINTAINER=	ken@pcbsd.org
COMMENT=	Graphical PBI module and package creator

LIB_DEPENDS=	QtSolutions_SingleApplication-head.1:${PORTSDIR}/devel/qt4-qtsolutions-singleapplication

USE_QT4=	corelib gui network webkit xml qmake_build moc_build rcc_build uic_build linguist
HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/EasyPBI-source

QMAKE_PRO=	EasyPBI.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix CONFIG+="configure" ${QMAKE_PRO}

.include <bsd.port.mk>
