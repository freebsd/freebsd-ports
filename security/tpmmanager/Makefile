# Created by: Norikatsu Shigemura <nork@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tpmmanager
PORTVERSION=	0.8.1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:C/\.1//}/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	TPM Manager

LICENSE=	GPLv2

LIB_DEPENDS=	libtspi.so:${PORTSDIR}/security/trousers

QT_NONSTANDARD=	YES
USE_QT4=	gui moc_build qmake_build rcc_build uic_build

HAS_CONFIGURE=	YES

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} tpmmanager.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/latex/${PORTNAME}.pdf ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/TPM_Manager.odt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
