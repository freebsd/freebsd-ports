# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mknmz-wwwoffle
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	www databases textproc
MASTER_SITES=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WWWOFFLE cache indexer for full-text search system Namazu

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/wwwoffle:www/wwwoffle
BUILD_DEPENDS=	${LOCALBASE}/bin/mknmz:databases/namazu2

USES=		perl5
HAS_CONFIGURE=	yes
NO_ARCH=	yes

PORTDOCS=	AUTHORS COPYING INSTALL INSTALL.ja NEWS README README.ja THANKS
OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for a in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${a} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
