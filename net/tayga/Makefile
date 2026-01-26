PORTNAME=	tayga
DISTVERSION=	0.9.5
CATEGORIES=	net

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	49f64b0.patch:-p1 \
		32cd0a7.patch:-p1 \
		b62e33f.patch:-p1 \
		6c298f2.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Userland stateless NAT64 daemon
WWW=		https://github.com/apalrd/tayga/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	64-bit time_t is required

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	apalrd
MAKE_ENV=	RELEASE=${DISTVERSION}
CFLAGS+=	-DTAYGA_CONF_PATH='\"${PREFIX}/etc/tayga.conf\"'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/tayga
	${INSTALL_DATA} ${WRKSRC}/tayga.conf.example ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
