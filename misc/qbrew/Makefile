# Created by: David Johnson <david@usermode.org>
# $FreeBSD$

PORTNAME=	qbrew
PORTVERSION=	0.4.1
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Homebrewer's recipe calculator

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gl qmake qt:5
USE_GL=		gl
USE_QT=		buildtools_build qmake_build \
		core gui printsupport widgets xml

QMAKE_ARGS=	CONFIG+="configure"
QMAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		DATADIR="${DATADIR}" \
		DOCDIR="${DOCSDIR}"

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qbrew

.include <bsd.port.mk>
