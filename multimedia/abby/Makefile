# Ports collection makefile for:	abby
# Date created:		March 1 2009
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	abby
PORTVERSION=	0.2.1
CATEGORIES=	multimedia net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	legatvs@gmail.com
COMMENT=	Front-end for cclive

RUN_DEPENDS=	cclive>=0.2.3:${PORTSDIR}/multimedia/cclive

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes

PLIST_FILES=	bin/abby

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} abby.pro

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abby ${PREFIX}/bin/abby

.include <bsd.port.post.mk>
