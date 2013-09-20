# $FreeBSD$

PORTNAME=	gtk-sharp-beans
PORTVERSION=	2.14.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Extensions on top of GTK-sharp

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gio-sharp-2.0.pc:${PORTSDIR}/devel/gio-sharp
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_BZIP2=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-extract:
	${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(libdir)data/pkgconfig|' \
	    ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
