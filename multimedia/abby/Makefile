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

USES=		qmake tar:bzip2
USE_QT4=	gui network xml moc_build rcc_build uic_build

PLIST_FILES=	bin/abby

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCCLIVE}
RUN_DEPENDS+=	cclive>=0.5.6:multimedia/cclive
.else
RUN_DEPENDS+=	clive>=2.2.5:multimedia/clive
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abby ${STAGEDIR}${PREFIX}/bin/abby

.include <bsd.port.mk>
