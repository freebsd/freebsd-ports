# Created by: Norikatsu Shigemura <nork@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tpmmanager
PORTVERSION=	0.8.1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:C/\.1//}/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	TPM Manager

LICENSE=	GPLv2

LIB_DEPENDS=	tspi:${PORTSDIR}/security/trousers

QT_NONSTANDARD=	YES
USE_QT4=	gui moc_build qmake_build rcc_build uic_build

HAS_CONFIGURE=	YES
MAKE_JOBS_SAFE=	YES

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} tpmmanager.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/latex/${PORTNAME}.pdf ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/TPM_Manager.odt ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
