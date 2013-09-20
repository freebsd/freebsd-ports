# Created by: ijliao
# $FreeBSD$

PORTNAME=	gsk
PORTVERSION=	1.0.63
CATEGORIES=	net devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C library for writing servers

USES=		pathfix pkgconfig
USE_GNOME=	glib20
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-gtk-doc
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|programs tests||' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|fread_unlocked|fread|' ${WRKSRC}/src/gsktable-flat.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.css ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.png ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
