PORTNAME=	prrte
DISTVERSION=	3.0.12
CATEGORIES=	net parallel sysutils
MASTER_SITES=	https://github.com/openpmix/prrte/releases/download/v${DISTVERSION}/

MAINTAINER=	laurent.chardon@gmail.com
COMMENT=	PMIx Reference RunTime Environment (PRRTE)
WWW=		https://docs.prrte.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	Not supported on 32-bits

LIB_DEPENDS=	libevent.so:devel/libevent \
		libhwloc.so:devel/hwloc2 \
		libpmix.so:net/pmix

USES=		compiler:c11 cpe gmake libtool localbase:ldflags \
		perl5 pkgconfig tar:bz2
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-hwloc=${LOCALBASE} \
		--with-libevent=${LOCALBASE} \
		--with-pmix=${LOCALBASE}
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE= DOCS
OPTIONS_SUB=	yes

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
