# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jojodiff
PORTVERSION=	0.8.1
CATEGORIES=	misc devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}08
DISTNAME=	jdiff${PORTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Diff and patch utilities for binary files

LICENSE=	GPLv3+

USES=		gmake tar:tgz
MAKE_ARGS=	CC="${CC}" CPP="${CXX}" CFLAGS="${CFLAGS}"
WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/jdiff bin/jptch
PORTDOCS=	readme.txt readme.htm

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E 's,P(RI|8)(zd|hkey), & ,g' \
		${WRKSRC}/JFileAhead.cpp ${WRKSRC}/JFileIStreamAhead.cpp \
		${WRKSRC}/JHashPos.cpp ${WRKSRC}/JOutAsc.cpp \
		${WRKSRC}/JOutRgn.cpp ${WRKSRC}/jpatch.cpp \
		${WRKSRC}/main.cpp
	@${REINPLACE_CMD} -e 's,is %d bit,is %zu bit,' \
		${WRKSRC}/jpatch.cpp ${WRKSRC}/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/j???? ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${TR} -d \\r < ${WRKSRC}/../${f} | iconv -f latin1 -t utf8 \
		> ${STAGEDIR}${DOCSDIR}/${f}
.endfor

.include <bsd.port.mk>
