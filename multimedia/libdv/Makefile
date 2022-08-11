PORTNAME=	libdv
DISTVERSION=	1.0.0
PORTREVISION=	8
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quasar DV codec (libdv) is a software codec for DV video

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt

USES=		localbase meson pkgconfig

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org/gstreamer
GL_ACCOUNT=	meson-ports
GL_PROJECT=	libdv
GL_COMMIT=	24218c36bed3b0a3bd5a57d5790ac12ade44e88d

USE_LDCONFIG=	yes

LDFLAGS_i386=	-Wl,-znotext

MESON_ARGS=	-Dpopt=enabled -Dtools=enabled

.include <bsd.port.mk>
