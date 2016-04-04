# $FreeBSD$

PORTNAME=	husky-htick

COMMENT=	Husky FTN file ticker

LIB_DEPENDS=	libfidoconfig.so:news/husky-fidoconf \
		libareafix.so:news/husky-areafix

ALL_TARGET=	all
INSTALL_TARGET=	install
USE_LDCONFIG=   yes
PLIST_FILES=	bin/htick man/man1/htick.1.gz

MASTERDIR=      ${.CURDIR}/../husky
COMPONENT_SUBDIR=       htick

# Settings below are required to handle texi output (html, INFO page)
USES+=			makeinfo
ALL_TARGET+=		doc
INSTALL_TARGET+=	install-doc
PORTDOCS=		htick.html
DOCSDIR=		${PREFIX}/share/doc/husky
INFO=			htick

post-patch:
	${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/htick.1

.include "${MASTERDIR}/Makefile"
