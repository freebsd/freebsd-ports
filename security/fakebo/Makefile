# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fakebo
PORTVERSION=	0.4.2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fake BackOrifice client emulator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USES=		autoreconf
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-extract:
	@${FIND} ${WRKSRC} -type l -delete

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fakebo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fakebo.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/fakebo.conf.dist ${STAGEDIR}${PREFIX}/etc/fakebo.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/custom.replies ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
