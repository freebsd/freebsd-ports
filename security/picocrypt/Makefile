PORTNAME=	picocrypt
PORTVERSION=	1.25
PORTREVISION=	3
CATEGORIES=	security

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Small, simple, yet very secure encryption tool

LICENSE=	GPLv3

USES=		gl gnome go:modules pkgconfig xorg
USE_GL=		gl
USE_GNOME=	gtk30
USE_XORG=	x11 xau xcb xdmcp
USE_GITHUB=	yes
GH_ACCOUNT=	HACKERALERT
GH_PROJECT=	Picocrypt
GH_TUPLE=	\
		HACKERALERT:clipboard:7345ba96aeca:hackeralert_clipboard/vendor/github.com/HACKERALERT/clipboard \
		HACKERALERT:crypto:ba8732acd7e7:hackeralert_crypto/vendor/github.com/HACKERALERT/crypto \
		HACKERALERT:dialog:a9e6303eda42:hackeralert_dialog/vendor/github.com/HACKERALERT/dialog \
		HACKERALERT:giu:a37934efe9a9:hackeralert_giu/vendor/github.com/HACKERALERT/giu \
		HACKERALERT:gl:402fdd216609:hackeralert_gl/vendor/github.com/HACKERALERT/gl \
		HACKERALERT:glfw:d0da149b3bef:hackeralert_glfw_glfw/vendor/github.com/HACKERALERT/glfw \
		HACKERALERT:imgui-go:da7cd33ca753:hackeralert_imgui_go/vendor/github.com/HACKERALERT/imgui-go \
		HACKERALERT:infectious:bb1303403749:hackeralert_infectious/vendor/github.com/HACKERALERT/infectious \
		HACKERALERT:mainthread:2ec9e701cc14:hackeralert_mainthread/vendor/github.com/HACKERALERT/mainthread \
		HACKERALERT:serpent:293b29869c66:hackeralert_serpent/vendor/github.com/HACKERALERT/serpent \
		HACKERALERT:sys:2e09c491f471:hackeralert_sys/vendor/github.com/HACKERALERT/sys \
		HACKERALERT:w32:4b84c2675d8d:hackeralert_w32/vendor/github.com/HACKERALERT/w32 \
		HACKERALERT:zxcvbn-go:f131a4666ad5:hackeralert_zxcvbn_go/vendor/github.com/HACKERALERT/zxcvbn-go

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${LN} -sf dlgs_linux.go \
	   ${WRKSRC}/vendor/github.com/HACKERALERT/dialog/dlgs_${OPSYS:tl}.go

.include <bsd.port.mk>
