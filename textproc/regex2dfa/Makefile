# $FreeBSD$

PORTNAME=	regex2dfa
DISTVERSION=	0.1.6
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Command-line utility that converts regular expressions to DFA

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gmake libtool
USE_GITHUB=	yes

GH_ACCOUNT=	kpdyer

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/${PORTNAME} include/${PORTNAME}.h lib/lib${PORTNAME}.a

post-patch:
	${REINPLACE_CMD} -e 's|-ldl||g' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/third_party/openfst/src/bin/Makefile.in \
		${WRKSRC}/third_party/openfst/src/extensions/far/Makefile.in \
		${WRKSRC}/third_party/openfst/src/extensions/linear/Makefile.in \
		${WRKSRC}/third_party/openfst/src/extensions/pdt/Makefile.in \
		${WRKSRC}/third_party/openfst/src/test/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/.libs/lib${PORTNAME}.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
