# $FreeBSD$

PORTNAME=	husky-htick
CATEGORIES=	news mail

MAINTAINER=     osharoiko@gmail.com
COMMENT=	Husky FTN file ticker

LIB_DEPENDS=	libfidoconfig.so:${PORTSDIR}/news/husky-fidoconf \
		libareafix.so:${PORTSDIR}/news/husky-areafix

ALL_TARGET=	all
INSTALL_TARGET=	install
USE_LDCONFIG=   yes
PLIST_FILES=	bin/htick man/man1/htick.1.gz

MASTERDIR=      ${.CURDIR}/../husky
COMPONENT_SUBDIR=       htick

# The texi files are too old for the ports texinfo
# The correct fix is to update the texi file so modern texinfo can use it
# Until then, disable installation of info page on FreeBSD 11 and DragonFly
# to unbreak the build on those platforms.
.if !exists(/usr/bin/makeinfo)
.else
USES+=			makeinfo
ALL_TARGET+=		doc
INSTALL_TARGET+=	install-doc
PORTDOCS=		htick.html
DOCSDIR=		${PREFIX}/share/doc/husky
INFO=			htick
.endif

post-patch:
	${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/htick.1

.include <bsd.port.mk>
