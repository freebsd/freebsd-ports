PORTNAME=	znapzend
PORTVERSION=	0.21.1
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ZFS-centric backup tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mbuffer>=0:misc/mbuffer \
		p5-IO-Pipely>=0:devel/p5-IO-Pipely \
		p5-Mojo-IOLoop-ForkCall>=0.21:www/p5-Mojo-IOLoop-ForkCall \
		p5-Mojolicious>=7.15:www/p5-Mojolicious \
		p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils
RUN_DEPENDS=	mbuffer>=0:misc/mbuffer \
		p5-IO-Pipely>=0:devel/p5-IO-Pipely \
		p5-Mojo-IOLoop-ForkCall>=0.21:www/p5-Mojo-IOLoop-ForkCall \
		p5-Mojolicious>=7.15:www/p5-Mojolicious \
		p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils

USES=		autoreconf gmake perl5
USE_GITHUB=	yes
GH_ACCOUNT=	oetiker
USE_RC_SUBR=	znapzend

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${SITE_PERL} \
		--prefix=${PREFIX}
CONFIGURE_ENV=	PERL5LIB=${SITE_PERL}
NO_ARCH=	yes

pre-configure:
	@${REINPLACE_CMD} -e '/thirdparty\/Makefile/d' ${WRKSRC}/configure.ac

post-configure:
	@${REINPLACE_CMD} -e 's/thirdparty//g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
