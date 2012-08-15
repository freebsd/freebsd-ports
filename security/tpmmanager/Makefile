# New ports collection makefile for:	tpmmanager
# Date created:				2011-01-02
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		tpmmanager
PORTVERSION=		0.8
PORTREVISION=	1
CATEGORIES=		security
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/${PORTNAME}-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		TPM Manager

LIB_DEPENDS=		tspi.2:${PORTSDIR}/security/trousers

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/COPYING

QT_NONSTANDARD=		YES
USE_QT4=		gui moc_build qmake_build rcc_build uic_build

HAS_CONFIGURE=		YES
MAKE_JOBS_SAFE=		YES

PLIST_FILES=		bin/${PORTNAME}

.include <bsd.port.pre.mk>
.if !defined(NOPORTDOCS)
PLIST_FILES+=		${DOCSDIR_REL}/${PORTNAME}.pdf \
			${DOCSDIR_REL}/TPM_Manager.odt
PLIST_DIRSTRY=		${DOCSDIR_REL}
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} tpmmanager.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME}        ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/latex/${PORTNAME}.pdf ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/TPM_Manager.odt       ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
