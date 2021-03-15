# Created by: ijliao
# $FreeBSD$

PORTNAME=	gsk
PORTVERSION=	1.0.63
PORTREVISION=	2
CATEGORIES=	net devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library for writing servers

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome libtool pathfix perl5 pkgconfig ssl
USE_PERL5=	build
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|programs tests||' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|fread_unlocked|fread|' ${WRKSRC}/src/gsktable-flat.c

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.css ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.png ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
