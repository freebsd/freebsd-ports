PORTNAME=	xhash
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.3
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	rbranco@suse.com
COMMENT=	Calculate hashes on files using goroutines
WWW=		https://github.com/ricardobranco777/xhash/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.23
USE_GITHUB=	yes
GH_ACCOUNT=	ricardobranco777
GH_TUPLE=	\
		golang:crypto:v0.28.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:sync:v0.8.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.26.0:golang_sys/vendor/golang.org/x/sys \
		klauspost:cpuid:v2.0.12:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		zeebo:blake3:v0.2.4:zeebo_blake3/vendor/github.com/zeebo/blake3

PLIST_FILES=	bin/xhash

.include <bsd.port.mk>
