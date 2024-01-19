PORTNAME=	vobcopy
PORTVERSION=	1.2.1
PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Decrypts and copies DVD .vob files
WWW=		https://github.com/barak/vobcopy

LICENSE=	GPLv2+

LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread

USES=		autoreconf localbase iconv
USE_GITHUB=	yes
GH_ACCOUNT=	barak
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CFLAGS+=	-DUSE_STATFS_FOR_DEV=1
MAKE_ARGS=	CCLD="${CC}"

PLIST_FILES=	bin/vobcopy \
		share/man/de/man1/vobcopy.1.gz \
		share/man/man1/vobcopy.1.gz

PORTDOCS=	COPYING ChangeLog Changelog README Release-Notes TODO \
		alternative_programs.txt

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_DEFAULT=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=   nls
NLS_LIBS=	-lintl

post-configure:
	${REINPLACE_CMD} -e 's|/usr/local/share/|${PREFIX}/share/|' \
		${WRKSRC}/vobcopy.c

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
