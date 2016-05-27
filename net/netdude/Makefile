# Created by: ijliao
# $FreeBSD$

PORTNAME=	netdude
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NETwork DUmp data Displayer and Editor for tcpdump tracefiles

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libnetdude.so:net/libnetdude

USES=		gettext iconv libtool gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc --with-html-dir=${DOCSDIR}
LIBS+=		-L${LOCALBASE}/lib -lltdl
USE_GNOME=	glib12 gtk12
INSTALL_TARGET=	install-strip

PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|DOC_MODULE = netdude|DOC_MODULE =|' \
		${WRKSRC}/doc/netdude-manual/Makefile.in

.include <bsd.port.mk>
