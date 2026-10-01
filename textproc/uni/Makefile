PORTNAME=	uni
PORTVERSION=	2.10.0
DISTVERSIONPREFIX=	v
PORTREVISION=	11
CATEGORIES=	textproc

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Query the Unicode database from the commandline
WWW=		https://github.com/arp242/uni

LICENSE=	MIT

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	arp242

GH_TUPLE=	\
		arp242:runewidth:v0.1.0:arp242_runewidth/vendor/zgo.at/runewidth \
		arp242:termtext:v1.5.0:arp242_termtext/vendor/zgo.at/termtext \
		arp242:zli:7bb9a5cf3265:arp242_zli/vendor/zgo.at/zli \
		arp242:zstd:7567984d0ee9:arp242_zstd/vendor/zgo.at/zstd \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg

GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}" -buildvcs=false

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	${MKDIR} ${WRKSRC}/vendor
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor/

# Maintenance target: regenerate files/modules.txt.
# Requires network access.  Run after updating DISTVERSION or GH_TUPLE.
# go mod vendor produces a complete vendor/modules.txt that covers both the
# modules in the tarball and those added via GH_TUPLE symlinks.
# (Copied from www/pomerium)

generate-modules-txt:
	@${ECHO_MSG} "Regenerating files/modules.txt (requires network access) ..."
	@${RM} -rf ${WRKDIR}/pomerium-modules-gen
	@${MKDIR} ${WRKDIR}/pomerium-modules-gen
	cd ${WRKDIR}/pomerium-modules-gen && \
		git clone --depth 1 -b ${DISTVERSIONPREFIX}${DISTVERSION} \
			https://github.com/${GH_ACCOUNT}/${GH_PROJECT}.git . && \
		${SED} -i '' '/^tool (/,/^)/d;/^ignore (/,/^)/d' go.mod && \
		GOWORK=off ${GO_CMD} mod tidy && \
		GOWORK=off ${GO_CMD} mod vendor && \
		${CP} vendor/modules.txt ${FILESDIR}/modules.txt
	@${ECHO_MSG} "Done.  Commit the updated files/modules.txt."

.include <bsd.port.mk>
