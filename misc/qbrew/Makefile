# Created by: David Johnson <david@usermode.org>
# $FreeBSD$

PORTNAME=	qbrew
PORTVERSION=	0.4.1
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	david@usermode.org
COMMENT=	A homebrewer's recipe calculator

USE_QT4=	qmake_build moc_build uic_build rcc_build xml gui
PORTDOCS=	*
HAS_CONFIGURE=	yes

CONFIGURE_ENV+=	BINDIR="${PREFIX}/bin" \
		DATADIR="${DATADIR}" \
		DOCDIR="${DOCSDIR}"

NO_STAGE=	yes
pre-configure:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/INSTALLS/s|doc||' \
		${WRKSRC}/qbrew.pro
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix CONFIG+="configure" qbrew.pro

post-install:
	${STRIP_CMD} ${PREFIX}/bin/qbrew

.include <bsd.port.mk>
