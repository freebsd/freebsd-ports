# New ports collection makefile for:	warden
# Date created:				Mar 29, 2010
# Whom:					Kris Moore
#
# $FreeBSD$
#

PORTNAME=	warden
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.pcbsd.org/pub/software/ \
		http://www.pcbsd.org/~kris/software/

MAINTAINER=	kmoore@freebsd.org
COMMENT=	PC-BSD's Jail Management Utility

RUN_DEPENDS=	pbreg:${PORTSDIR}/sysutils/pbreg

WRKSRC=		${WRKDIR}/warden

USE_GZIP=	yes
USE_QMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui qmake_build moc_build rcc_build uic_build
HAS_CONFIGURE=	yes

QMAKE_PRO=	warden.pro
QMAKE_ARGS=	-unix -recursive ${QMAKE_PRO}

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
				 ${WRKSRC}/warden.pro \
				 ${WRKSRC}/scripts/rc.d/wardenrc \
				 ${WRKSRC}/src/src.pro \
				 ${WRKSRC}/src/dialogwarden.h
	${RM} ${WRKSRC}/scripts/rc.d/wardenrc.bak

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix CONFIG+="configure" ${QMAKE_PRO}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
RUN_DEPENDS+=	xz:${PORTSDIR}/archivers/xz
.endif

.include <bsd.port.post.mk>
