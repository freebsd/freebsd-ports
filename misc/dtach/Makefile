# Created by: Bjorn Lindstrom <bkhl@elektrubadur.se>
# $FreeBSD$

PORTNAME=		dtach
PORTVERSION=		0.8
PORTREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulates the detach feature of screen

GNU_CONFIGURE=	yes
ALL_TARGET=	dtach

MAN1=		dtach.1
PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dtach ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/dtach.1 ${MAN1PREFIX}/man/man1/

.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
