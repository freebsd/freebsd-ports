# Created by: Toni Gundogdu <legatvs@gmail.com>
# $FreeBSD$

PORTNAME=	abby
PORTVERSION=	0.4.8
PORTREVISION=	3
CATEGORIES=	multimedia net
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/abby/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Front-end for c/clive

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake qt:4 tar:bzip2
USE_QT=		gui network xml moc_build rcc_build uic_build

PLIST_FILES=	bin/abby

OPTIONS_DEFINE=	CCLIVE
OPTIONS_DEFAULT=	CCLIVE
CCLIVE_DESC=	Use cclive backend (instead of clive)

CCLIVE_RUN_DEPENDS=	cclive>=0.5.6:multimedia/cclive
CCLIVE_RUN_DEPENDS_OFF=	clive>=2.2.5:multimedia/clive

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abby ${STAGEDIR}${PREFIX}/bin/abby

.include <bsd.port.mk>
