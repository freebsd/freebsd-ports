PORTNAME=	unrtf
PORTVERSION=	0.21.10
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	jharris@widomaker.com
COMMENT=	Converter from RTF to several formats, including HTML and LaTeX

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cpe gmake iconv localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
CPE_VENDOR=	unrtf_project
TEST_TARGET=	check

LDFLAGS+=	${ICONV_LIB}

post-patch:
	@${FIND} -X ${WRKSRC} -type f -and -name "*.[1h]" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|/usr/local/lib/unrtf/|${DATADIR}/|g'
	@${REINPLACE_CMD} -e '/^attr_get_param/,/^}/s/return;/return NULL;/' \
		${WRKSRC}/src/attr.c

.include <bsd.port.mk>
