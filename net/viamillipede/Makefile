PORTNAME=	viamillipede
DISTVERSIONPREFIX=	v
DISTVERSION=	0.89
CATEGORIES=	net

MAINTAINER=	ash_ports@aeria.net
COMMENT=	Parallel TCP for pipe transport
WWW=		https://github.com/agokhale/viamillipede

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	ld: error: /usr/lib/dtrace/drti.o is incompatible with dtrace_viamillipede.o.xxx
NOT_FOR_ARCHS=	armv6 armv7
NOT_FOR_ARCHS_REASON=	libdtrace/common/dt_link.c(843): arm not implemented

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	agokhale

PLIST_FILES=	bin/viamillipede \
		man/man1/viamillipede.1.gz

.include <bsd.port.mk>
