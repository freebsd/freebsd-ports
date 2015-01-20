# $FreeBSD$

PORTNAME=	simple-mtpfs
PORTVERSION=	0.2.s20140709
PORTREVISION=	2
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple MTP fuse filesystem driver

LICENSE=	GPLv2 # or any later version

LIB_DEPENDS=	libmtp.so:${PORTSDIR}/multimedia/libmtp

USE_GITHUB=	yes
GH_ACCOUNT=	phatina
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	74dfce6

USES=		autoreconf compiler:c++11-lib fuse pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules
MAKEFILE=	makefile
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	AUTHORS NEWS README.md

OPTIONS_DEFINE=	DOCS

.if !exists(/usr/libdata/pkgconfig/libusb-1.0.pc)
CONFIGURE_ENV+=	LIBUSB1_CFLAGS=" " LIBUSB1_LIBS="-lusb"
.endif

# XXX move to PREFIX when bug 193596 lands
.if exists(/etc/autofs)
PLIST_FILES+=	/etc/autofs/special_${PORTNAME}
SUB_FILES+=	special_${PORTNAME}
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.if exists(/etc/autofs)
	@${MKDIR} ${STAGEDIR}/etc/autofs
	${INSTALL_SCRIPT} ${WRKDIR}/special_${PORTNAME} \
		${STAGEDIR}/etc/autofs
.endif

.include <bsd.port.mk>
