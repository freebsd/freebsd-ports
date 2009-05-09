# New ports collection makefile for:	gsk
# Date created:				May 1, 2001
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	gsk
PORTVERSION=	1.0.63
CATEGORIES=	net devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C library for writing servers

USE_GNOME=	glib20 gnomehack
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--disable-gtk-doc
USE_LDCONFIG=	yes

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
