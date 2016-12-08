# $FreeBSD$

PORTNAME=	pilrc
PORTVERSION=	3.2
PORTREVISION=	5
CATEGORIES=	palm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resource compiler for Pilot applications

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/pilrc-${PORTVERSION}/unix
CONFIGURE_ARGS=	--enable-pilrcui

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pilrc ${WRKSRC}/pilrcui ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/../doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
