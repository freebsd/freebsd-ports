# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	ansifilter
PORTVERSION=	1.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Customizable ANSI Code Converter

LICENSE=	GPLv3

USE_BZIP2=	yes
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CXX}" \
		CFLAGS="${CXXFLAGS} ${CPPFLAGS} -c" \
		LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

PORTDOCS=	ChangeLog README

post-patch:
	@${REINPLACE_CMD} -e \
		's|^PREFIX =|PREFIX ?=|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1.gz ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
