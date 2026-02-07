PORTNAME=	htop
PORTVERSION=	3.4.1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/htop-dev/htop/releases/download/${PORTVERSION}/

MAINTAINER=	gaod@hychen.org
COMMENT=	Better top(1) - interactive process viewer
WWW=		https://htop.dev/ \
		https://github.com/htop-dev/htop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses tar:xz

CONFIGURE_ARGS=	--enable-unicode
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/htop \
		share/man/man1/htop.1.gz \
		share/applications/htop.desktop \
		share/icons/hicolor/scalable/apps/htop.svg \
		share/pixmaps/htop.png

OPTIONS_DEFINE=	LSOF

LSOF_RUN_DEPENDS=	lsof:sysutils/lsof

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
CONFIGURE_ARGS+=--enable-libunwind
LIB_DEPENDS+=	libunwind.so:devel/libunwind
USES+=		localbase
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|${PORTVERSION}-${PORTVERSION}|${PORTVERSION}|' ${WRKSRC}/configure

.include <bsd.port.mk>
