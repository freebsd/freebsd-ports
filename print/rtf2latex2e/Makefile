PORTNAME=	rtf2latex2e
DISTVERSION=	2-2-3
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-unix/2-2

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Newer filter that converts RTF (MS Rich Text Format) into LaTeX
WWW=		https://sourceforge.net/projects/rtf2latex2e/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/GPL_license

USES=		gmake

MAKE_ARGS=	CC="${CC}" mandir=${MANDIRS}
TEST_TARGET=	test

CFLAGS+=	-fcommon

TESTING_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
