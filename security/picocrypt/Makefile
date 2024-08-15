PORTNAME=	picocrypt
DISTVERSION=	1.34
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Small, simple, yet very secure encryption tool
WWW=		https://github.com/HACKERALERT/Picocrypt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 mips64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	upstream only supports 64-bit
# https://github.com/HACKERALERT/Picocrypt/issues/127

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		gl gnome go:modules pkgconfig xorg
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_XORG=	x11 xau xcb xdmcp
USE_GITHUB=	yes
GH_ACCOUNT=	HACKERALERT
GH_PROJECT=	Picocrypt
GH_TUPLE=	HACKERALERT:dialog:af3bc34fe379:hackeralert_dialog/vendor/github.com/HACKERALERT/dialog \
		HACKERALERT:giu:211c1da061d9:hackeralert_giu/vendor/github.com/HACKERALERT/giu \
		HACKERALERT:gl:73af36e130d3:hackeralert_gl/vendor/github.com/HACKERALERT/gl \
		HACKERALERT:glfw:c08d79e41abe:hackeralert_glfw_glfw/vendor/github.com/HACKERALERT/glfw \
		HACKERALERT:imgui-go:1d1c00423178:hackeralert_imgui_go/vendor/github.com/HACKERALERT/imgui-go \
		HACKERALERT:infectious:b9ce72346a19:hackeralert_infectious/vendor/github.com/HACKERALERT/infectious \
		HACKERALERT:mainthread:2ec9e701cc14:hackeralert_mainthread/vendor/github.com/HACKERALERT/mainthread \
		HACKERALERT:serpent:293b29869c66:hackeralert_serpent/vendor/github.com/HACKERALERT/serpent \
		HACKERALERT:w32:76f2a4b526bd:hackeralert_w32/vendor/github.com/HACKERALERT/w32 \
		HACKERALERT:zxcvbn-go:fa924b767f89:hackeralert_zxcvbn_go/vendor/github.com/HACKERALERT/zxcvbn-go \
		golang:crypto:v0.22.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:9a28524796a5:golang_sys/vendor/golang.org/x/sys

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${LN} -sf dlgs_linux.go \
	   ${WRKSRC}/vendor/github.com/HACKERALERT/dialog/dlgs_${OPSYS:tl}.go

.include <bsd.port.mk>
