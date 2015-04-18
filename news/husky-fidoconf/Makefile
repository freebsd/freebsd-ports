# $FreeBSD$

PORTNAME=	husky-fidoconf
CATEGORIES=	news mail

MAINTAINER=	osharoiko@gmail.com
COMMENT=	Husky FTN configuration library

LIB_DEPENDS=	libsmapi.so:${PORTSDIR}/news/husky-smapi

USES+=		perl5 shebangfix
SHEBANG_FILES=	util/fconf2areasbbs.pl util/fconf2na.pl util/sq2fc.pl
USE_LDCONFIG=   yes
INSTALL_TARGET=	install install-man

MASTERDIR=      ${.CURDIR}/../husky
COMPONENT_SUBDIR=       fidoconf

post-patch:
	${REINPLACE_CMD} -e 's^/path/to/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/linkedto.1

# The texi files are too old for the ports texinfo
# The correct fix is to update the texi file so modern texinfo can use it
# Until then, disable installation of info page on FreeBSD 11 and DragonFly
# to unbreak the build on those platforms.
.if !exists(/usr/bin/makeinfo)
	${REINPLACE_CMD} -e '/cd doc /d' ${WRKSRC}/Makefile
.else
USES+=		makeinfo
PORTDOCS=	fidoconfig.html
DOCSDIR=	${PREFIX}/share/doc/husky
INFO=		fidoconfig
.endif

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

.include <bsd.port.mk>
