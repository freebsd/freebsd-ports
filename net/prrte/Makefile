PORTNAME=	prrte
DISTVERSION=	3.0.14
CATEGORIES=	net parallel sysutils
MASTER_SITES=	https://github.com/openpmix/prrte/releases/download/v${DISTVERSION}/

MAINTAINER=	laurent@FreeBSD.org
COMMENT=	PMIx Reference RunTime Environment (PRRTE)
WWW=		https://docs.prrte.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	Not supported on 32-bits

LIB_DEPENDS=	libevent_core.so:devel/libevent \
		libhwloc.so:devel/hwloc2 \
		libpmix.so:net/pmix

USES=		compiler:c11 cpe gmake libtool perl5 pkgconfig tar:bz2
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-hwloc=${LOCALBASE} \
		--with-libevent=${LOCALBASE} \
		--with-pmix=${LOCALBASE} \
		--without-libltdl \
		--without-lsf \
		--without-pbs \
		--without-sge \
		--without-tm
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS SLURM
OPTIONS_DEFAULT=	SLURM
OPTIONS_SUB=		yes

SLURM_DESC=	Enable SLURM support

SLURM_CONFIGURE_WITH=	slurm

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
