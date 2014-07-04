# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ortp
PORTVERSION=	0.13.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	linphone/ortp/sources

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Real-time Transport Protocol (RTP) stack

USES=		libtool pathfix pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/configure

.include <bsd.port.mk>
