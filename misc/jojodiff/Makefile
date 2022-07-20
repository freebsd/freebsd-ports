PORTNAME=	jojodiff
PORTVERSION=	0.8.5
CATEGORIES=	misc devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}08
DISTNAME=	jdiff${PORTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Diff and patch utilities for binary files

LICENSE=	GPLv3+

USES=		gmake tar:tgz
MAKE_ARGS=	CC="${CC}" CPP="${CXX}" CFLAGS="${CFLAGS}"
ALL_TARGET=	jdiff
WRKSRC_SUBDIR=	src

CONFLICTS_INSTALL=	py*-jsondiff # bin/jdiff

PLIST_FILES=	bin/jdedup bin/jdiff bin/jpatch bin/jtst
PORTDOCS=	readme.txt readme.htm

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jdiff ${STAGEDIR}${PREFIX}/bin
.for l in jdedup jpatch jtst
	${LN} -sf jdiff ${STAGEDIR}${PREFIX}/bin/${l}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TR} -d \\r < ${WRKSRC}/../readme.htm | ${SED} 's,iso-8859-1,utf-8,' \
		| iconv -f latin1 -t utf8 > ${STAGEDIR}${DOCSDIR}/readme.htm
	${TR} -d \\r < ${WRKSRC}/../readme.txt \
		> ${STAGEDIR}${DOCSDIR}/readme.txt

.include <bsd.port.mk>
