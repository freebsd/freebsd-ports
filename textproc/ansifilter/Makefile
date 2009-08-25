# New ports collection makefile for:	ansifilter
# Date created:				09 July 2008
# Whom:					Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	ansifilter
PORTVERSION=	1.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	Customizable ANSI Code Converter

USE_BZIP2=	yes
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CXX}" \
		CFLAGS="${CXXFLAGS} ${CPPFLAGS} -c" \
		LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/ansifilter

MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog README
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|^PREFIX =|PREFIX ?=|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1}.gz ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
