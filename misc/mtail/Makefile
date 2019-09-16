# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mtail
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://matt.immute.net/src/mtail/

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Small tail workalike that performs output coloring

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:2.7,run shebangfix tar:tgz

SHEBANG_FILES=	${WRKSRC}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGES README
PORTEXAMPLES=	mtailrc

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} mtailrc.sample \
		${STAGEDIR}${EXAMPLESDIR}/mtailrc)

.include <bsd.port.mk>
