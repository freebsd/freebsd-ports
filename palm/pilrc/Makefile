# $FreeBSD$

PORTNAME=	pilrc
PORTVERSION=	3.2
PORTREVISION=	4
CATEGORIES=	palm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resource compiler for Pilot applications

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/pilrc-${PORTVERSION}/unix
CONFIGURE_ARGS+=	--enable-pilrcui

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pilrc ${WRKSRC}/pilrcui ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/../doc/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
