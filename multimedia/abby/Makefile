# Ports collection makefile for:	abby
# Date created:		March 1 2009
# Whom:			Toni Gundogdu <legatvs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	abby
PORTVERSION=	0.4.0
CATEGORIES=	multimedia net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	legatvs@gmail.com
COMMENT=	Front-end for c/clive

OPTIONS=	CCLIVE "Use cclive as back-end" on \
		CLIVE  "Use clive as back-end" off

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network xml moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes

PLIST_FILES=	bin/abby

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} "QT+=network xml" -unix PREFIX=${PREFIX} abby.pro

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abby ${PREFIX}/bin/abby

.if defined(WITHOUT_CCLIVE)
RUN_DEPENDS+=	cclive>=0.4.4:${PORTSDIR}/multimedia/cclive
.endif

.if defined(WITH_CLIVE)
RUN_DEPENDS+=	clive>=2.2.1:${PORTSDIR}/multimedia/clive
.endif

.include <bsd.port.post.mk>
