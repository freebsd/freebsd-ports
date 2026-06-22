PORTNAME=	watch
DISTVERSION=	4.0.6
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/procps-ng/Production
PKGNAMEPREFIX=	gnu-
DISTNAME=	procps-ng-${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	GNU watch command
WWW=		https://gitlab.com/procps-ng/procps/

LICENSE=	GPLv2

USES=		gettext-tools gmake libtool localbase:ldflags \
		ncurses pkgconfig tar:xz

GNU_CONFIGURE=	yes

ALL_TARGET=	src/watch

PLIST_FILES=	bin/${PKGBASE} \
		share/man/man1/gnu-watch.1.gz

OPTIONS_DEFINE=		NLS UNICODE
OPTIONS_DEFAULT=	UNICODE

NLS_USES=			gettext
NLS_CONFIGURE_OFF=		--disable-nls

UNICODE_CONFIGURE_ENABLE=	watch8bit

post-patch:
	@${REINPLACE_CMD} -e '\
		s|WATCH|${PKGBASE:tu}|g; \
		s|watch \\-|${PKGBASE} \\-|g; \
		s|B watch|B ${PKGBASE}|g; \
		s|fBwatch|fB${PKGBASE}|g; \
		s|watch uname|${PKGBASE} uname|g' \
		${PATCH_WRKSRC}/man/watch.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/watch \
		${STAGEDIR}${PREFIX}/bin/gnu-watch
	${INSTALL_MAN} ${WRKSRC}/man/watch.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/gnu-watch.1

.include <bsd.port.mk>
