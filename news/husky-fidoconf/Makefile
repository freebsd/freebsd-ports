# $FreeBSD$

PORTNAME=	husky-fidoconf

COMMENT=	Husky FTN configuration library

LICENSE=	LGPL20

LIB_DEPENDS=	libsmapi.so:news/husky-smapi \
		libhusky.so:news/husky-huskylib

USES+=		perl5 shebangfix
SHEBANG_FILES=	fidoconf/util/fconf2areasbbs.pl fidoconf/util/fconf2na.pl fidoconf/util/sq2fc.pl
USE_LDCONFIG=	yes
INSTALL_TARGET=	install install-man

MASTERDIR=	${.CURDIR}/../husky
COMPONENT_SUBDIR=fidoconf

# Settings below are required to handle texi output (html, INFO page)
USES+=		makeinfo
PORTDOCS=	fidoconfig.html
DOCSDIR=	${PREFIX}/share/doc/husky
INFO=		fidoconfig
MAKE_ARGS=	INFODIR=${PREFIX}/${INFO_PATH}

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's^/path/to/config^${PREFIX}/etc/fido/config^' \
		${BUILD_WRKSRC}/man/linkedto.1

post-install:
	${LN} -sf fconf2.1 ${STAGEDIR}${PREFIX}/man/man1/fconf2aquaed.1
	${LN} -sf fconf2.1 ${STAGEDIR}${PREFIX}/man/man1/fconf2areasbbs.1
	${LN} -sf fconf2.1 ${STAGEDIR}${PREFIX}/man/man1/fconf2binkd.1
	${LN} -sf fconf2.1 ${STAGEDIR}${PREFIX}/man/man1/fconf2dir.1
	${LN} -sf fconf2.1 ${STAGEDIR}${PREFIX}/man/man1/fconf2fidogate.1
	${LN} -sf fconf2.1 ${STAGEDIR}${PREFIX}/man/man1/fconf2golded.1
	${LN} -sf fconf2.1 ${STAGEDIR}${PREFIX}/man/man1/fconf2msged.1
	${LN} -sf fconf2.1 ${STAGEDIR}${PREFIX}/man/man1/fconf2na.pl.1
	${LN} -sf fconf2.1 ${STAGEDIR}${PREFIX}/man/man1/fconf2squish.1
	${LN} -sf fconf2.1 ${STAGEDIR}${PREFIX}/man/man1/fconf2tornado.1
	${LN} -sf fconf2.1 ${STAGEDIR}${PREFIX}/man/man1/fecfg2fconf.1

.include "${MASTERDIR}/Makefile"
