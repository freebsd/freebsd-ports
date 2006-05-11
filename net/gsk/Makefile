# New ports collection makefile for:	gsk
# Date created:				May 1, 2001
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	gsk
PORTVERSION=	1.0.17
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	babak@farrokhi.net
COMMENT=	A C library for writing servers

USE_GNOME=	glib20 gnomehack gnometarget
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS+=	--disable-gtk-doc

PORTDOCS=	*

.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--disable-ssl
PLIST_SUB+=	OPENSSL="@comment "
.else
USE_OPENSSL=	yes
PLIST_SUB+=	OPENSSL=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^\(HTML_DIR\).*|\1 = ${PREFIX}/share/doc|' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|programs tests||' \
		${WRKSRC}/src/Makefile.in

.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = \).*|\1 src|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
