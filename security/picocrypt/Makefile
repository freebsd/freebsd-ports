PORTNAME=	picocrypt
DISTVERSION=	1.48 # Missing modules.txt, generate one with `go mod vendor` and place it in ${FILESDIR}
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Small, simple, yet very secure encryption tool
WWW=		https://github.com/Picocrypt/Picocrypt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 mips64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	upstream only supports 64-bit
# https://github.com/HACKERALERT/Picocrypt/issues/127

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		gl gnome go:modules pkgconfig xorg
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf gtk30
USE_XORG=	x11 xau xcb xdmcp
USE_GITHUB=	yes
GH_ACCOUNT=	Picocrypt
GH_PROJECT=	Picocrypt
GH_TUPLE=	Picocrypt:dialog:78f7b909315b:picocrypt_dialog/vendor/github.com/Picocrypt/dialog \
		Picocrypt:giu:fe90a482e6f2:picocrypt_giu/vendor/github.com/Picocrypt/giu \
		Picocrypt:gl:767b58dbf936:picocrypt_gl/vendor/github.com/Picocrypt/gl \
		Picocrypt:glfw:7b96bfdb8dd8:picocrypt_glfw_glfw/vendor/github.com/Picocrypt/glfw \
		Picocrypt:imgui-go:d86b230f5fbb:picocrypt_imgui_go/vendor/github.com/Picocrypt/imgui-go \
		Picocrypt:infectious:9f88c6307b39:picocrypt_infectious/vendor/github.com/Picocrypt/infectious \
		Picocrypt:mainthread:496f638392b3:picocrypt_mainthread/vendor/github.com/Picocrypt/mainthread \
		Picocrypt:serpent:9ad6ab254fd7:picocrypt_serpent/vendor/github.com/Picocrypt/serpent \
		Picocrypt:w32:1183079d4d57:picocrypt_w32/vendor/github.com/Picocrypt/w32 \
		Picocrypt:zxcvbn-go:d59695960527:picocrypt_zxcvbn_go/vendor/github.com/Picocrypt/zxcvbn-go \
		golang:crypto:v0.37.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.32.0:golang_sys/vendor/golang.org/x/sys

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	@${LN} -sf dlgs_linux.go \
		${WRKSRC}/vendor/github.com/Picocrypt/dialog/dlgs_${OPSYS:tl}.go
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor/

.include <bsd.port.mk>
