# $FreeBSD$

PORTNAME=	pilrc
PORTVERSION=	3.2
PORTREVISION=	3
CATEGORIES=	palm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resource compiler for Pilot applications

WRKSRC=		${WRKDIR}/pilrc-${PORTVERSION}/unix
CONFIGURE_ARGS+=	--enable-pilrcui

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pilrc ${WRKSRC}/pilrcui ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
