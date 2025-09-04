PORTNAME=	jest
DISTVERSION=	3.0.16
PORTREVISION=	31
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ReST api for creating and managing FreeBSD jails written in Go
WWW=		https://github.com/tabrarg/jest

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	tabrarg
GH_TAGNAME=	f76bc46
GH_TUPLE=	\
		andybalholm:brotli:5f990b6:brotli/vendor/github.com/andybalholm/brotli \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		cespare:xxhash:v2.0.0:xxhash/vendor/github.com/cespare/xxhash \
		dsnet:compress:cc9eb1d:dsnet_compress/vendor/github.com/dsnet/compress \
		golang:gddo:af0f2af:golang_gddo/vendor/github.com/golang/gddo \
		golang:snappy:2e65f85:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		gorilla:mux:v1.7.3:mux/vendor/github.com/gorilla/mux \
		jlaffaye:ftp:c1312a7:ftp/vendor/github.com/jlaffaye/ftp \
		klauspost:compress:v1.7.0:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.2.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		klauspost:crc32:v1.2.0:klauspost_crc32/vendor/github.com/klauspost/crc32 \
		klauspost:pgzip:v1.2.1:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		mholt:archiver:v2.0:archiver/vendor/github.com/mholt/archiver \
		mistifyio:go-zfs:v2.1.1:go_zfs/vendor/github.com/mistifyio/go-zfs \
		nwaples:rardecode:v1.0.0:rardecode/vendor/github.com/nwaples/rardecode \
		pierrec:lz4:v2.0.5:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		sirupsen:logrus:v1.4.2:logrus/vendor/github.com/sirupsen/logrus \
		ulikunitz:xz:v0.5.6:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		xi2:xz:48954b6:xi2_xz/vendor/github.com/xi2/xz

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
