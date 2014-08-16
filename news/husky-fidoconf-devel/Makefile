# $FreeBSD$

PORTNAME=	husky-fidoconf
CATEGORIES=	news mail

MAINTAINER=	osharoiko@gmail.com
COMMENT=	Husky FTN configuration library (development version)

LIB_DEPENDS=	libsmapi.so:${PORTSDIR}/news/husky-smapi-devel

CONFLICTS=	husky-fidoconf-[0-9]*

USES+=		perl5 shebangfix makeinfo
SHEBANG_FILES=	util/fconf2areasbbs.pl util/fconf2na.pl util/sq2fc.pl
USE_LDCONFIG=   yes
INSTALL_TARGET=	install install-man

MASTERDIR=      ${.CURDIR}/../husky-devel
COMPONENT_SUBDIR=       fidoconf

post-patch:
	${REINPLACE_CMD} -e 's^/path/to/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/linkedto.1

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
