PORTNAME=	flex
PORTVERSION=	2.6.4
PORTREVISION=	2
CATEGORIES=	textproc devel
MASTER_SITES=	https://github.com/westes/flex/releases/download/v${PORTVERSION}/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Fast lexical analyzer generator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man

USES=		bison:alias cpe gmake libtool makeinfo
CPE_VENDOR=	${PORTNAME}_project
GNU_CONFIGURE=	yes
# install flex header to its own dir to avoid conflict with system flex.
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/flex --disable-shared
CONFIGURE_ENV=	MAKEINFO="${MAKEINFO} --no-split" \
		CC_FOR_BUILD="${CC}" \
                CFLAGS_FOR_BUILD="${CFLAGS}" \
                CPPFLAGS_FOR_BUILD="${CPPFLAGS}" \
                CXX_FOR_BUILD="${CXX}" \
                CXXFLAGS_FOR_BUILD="${CXXFLAGS}" \
                LDFLAGS_FOR_BUILD="${LDFLAGS}"
INSTALL_TARGET=	install-strip

INFO=		flex
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext iconv
NLS_CONFIGURE_ENABLE=	nls

post-patch:	.SILENT
	${REINPLACE_CMD} -Ee 's/tests//' \
		-e '/mode=compile ..CC/s/\\$$/-fPIC -DPIC &/' \
		${WRKSRC}/Makefile.in
	${RM} ${WRKSRC}/doc/*.info*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}/
	${RM} ${STAGEDIR}${EXAMPLESDIR}/Makefile.am

.include <bsd.port.mk>
