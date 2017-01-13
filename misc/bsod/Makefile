# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsod
PORTVERSION=	0.1
CATEGORIES=	misc
MASTER_SITES=	https://www.vanheusden.com/bsod/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Experience the authentic Microsoft Windows experience

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		ncurses tar:tgz

PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I${NCURSESINC} -L${NCURSESLIB} -lncurses -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
