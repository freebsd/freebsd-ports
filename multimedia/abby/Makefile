# Created by: Toni Gundogdu <legatvs@gmail.com>
# $FreeBSD$

PORTNAME=	abby
PORTVERSION=	0.4.8
PORTREVISION=	3
CATEGORIES=	multimedia net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Front-end for c/clive

OPTIONS_DEFINE=	CCLIVE
OPTIONS_DEFAULT=	CCLIVE
CCLIVE_DESC=	Use cclive backend (instead of clive)

USE_BZIP2=	yes
USE_QT4=	gui network xml moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
QMAKE_ARGS=	-unix -recursive PREFIX=${PREFIX} ${QMAKE_PRO}
QMAKE_PRO=	abby.pro

PLIST_FILES=	bin/abby

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCCLIVE}
RUN_DEPENDS+=	cclive>=0.5.6:${PORTSDIR}/multimedia/cclive
.else
RUN_DEPENDS+=	clive>=2.2.5:${PORTSDIR}/multimedia/clive
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abby ${PREFIX}/bin/abby

.include <bsd.port.mk>
