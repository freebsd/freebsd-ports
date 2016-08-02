# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	csvdiff
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
#DISTNAME=	${PORTNAME}_${PORTVERSION:S,.,-,g}
DISTNAME=	${PORTNAME}17

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compare/diff two (comma) separated files with each other

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	csvdiff.pl
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}

PORTDOCS=	CHANGES README TODO
PLIST_FILES=	bin/csvdiff

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
