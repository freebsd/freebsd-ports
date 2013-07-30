# Created by: MANTANI Nobutaka <nobutaka@freebsd.org>
# $FreeBSD$

PORTNAME=	dd_rescue
PORTVERSION=	1.32
CATEGORIES=	sysutils
MASTER_SITES=	http://www.garloff.de/kurt/linux/ddrescue/ \
		http://fossies.org/unix/privat/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	dd tool suitable for rescuing data from a medium with errors

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_CSTD=	gnu89

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	default

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dd_rescue ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/README.dd_rescue ${DOCSDIR}
.endif

.include <bsd.port.mk>
