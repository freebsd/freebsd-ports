# Ports collection makefile for:	abby
# Date created:		March 1 2009
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	abby
PORTVERSION=	0.4.8
PORTREVISION=	2
CATEGORIES=	multimedia net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Front-end for c/clive

OPTIONS=	CCLIVE "Use cclive backend (instead of clive)" on

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network xml moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
QMAKE_ARGS=	-unix -recursive PREFIX=${PREFIX} ${QMAKE_PRO}
QMAKE_PRO=	abby.pro

PLIST_FILES=	bin/abby

.include <bsd.port.pre.mk>

.if defined(WITH_CCLIVE)
RUN_DEPENDS+=	cclive>=0.5.6:${PORTSDIR}/multimedia/cclive
.else
RUN_DEPENDS+=	clive>=2.2.5:${PORTSDIR}/multimedia/clive
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abby ${PREFIX}/bin/abby

.include <bsd.port.post.mk>
