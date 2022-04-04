# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	picocrypt
PORTVERSION=	1.24
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
		HACKERALERT:dialog:24c44f67b0e0:hackeralert_dialog/vendor/github.com/HACKERALERT/dialog \
		HACKERALERT:giu:0a3331212c4e:hackeralert_giu/vendor/github.com/HACKERALERT/giu \
		HACKERALERT:gl:e8bf2db61361:hackeralert_gl/vendor/github.com/HACKERALERT/gl \
		HACKERALERT:glfw:d0da149b3bef:hackeralert_glfw_glfw/vendor/github.com/HACKERALERT/glfw \
		HACKERALERT:imgui-go:793c12595b34:hackeralert_imgui_go/vendor/github.com/HACKERALERT/imgui-go \
		HACKERALERT:infectious:3073de4d0e0a:hackeralert_infectious/vendor/github.com/HACKERALERT/infectious \
		HACKERALERT:mainthread:2ec9e701cc14:hackeralert_mainthread/vendor/github.com/HACKERALERT/mainthread \
		HACKERALERT:serpent:293b29869c66:hackeralert_serpent/vendor/github.com/HACKERALERT/serpent \
		HACKERALERT:w32:4b84c2675d8d:hackeralert_w32/vendor/github.com/HACKERALERT/w32 \
		HACKERALERT:zxcvbn-go:f131a4666ad5:hackeralert_zxcvbn_go/vendor/github.com/HACKERALERT/zxcvbn-go \
		golang:crypto:2c7772ba3064:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:36772127a21f:golang_sys/vendor/golang.org/x/sys

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${LN} -sf dlgs_linux.go \
	   ${WRKSRC}/vendor/github.com/HACKERALERT/dialog/dlgs_${OPSYS:tl}.go

.include <bsd.port.mk>
