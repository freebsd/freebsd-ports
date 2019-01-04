# $FreeBSD$

PORTNAME=		znapzend
PORTVERSION=		0.18.0
DISTVERSIONPREFIX=	v
CATEGORIES=		sysutils

MAINTAINER=	skalmanman@gmail.com
COMMENT=	ZnapZend is a ZFS centric backup tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Pod-Simple>=0:textproc/p5-Pod-Simple \
			p5-IO-Pipely>=0:devel/p5-IO-Pipely \
			p5-Mojolicious>=7.15:www/p5-Mojolicious \
			p5-Mojo-IOLoop-ForkCall>=0.17:www/p5-Mojo-IOLoop-ForkCall \
			p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils \
			p5-Test-Harness>=0:devel/p5-Test-Harness \
			mbuffer>=0:misc/mbuffer
RUN_DEPENDS=	p5-Pod-Simple>=0:textproc/p5-Pod-Simple \
			p5-IO-Pipely>=0:devel/p5-IO-Pipely \
			p5-Mojolicious>=7.15:www/p5-Mojolicious \
			p5-Mojo-IOLoop-ForkCall>=0.17:www/p5-Mojo-IOLoop-ForkCall \
			p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils \
			p5-Test-Harness>=0:devel/p5-Test-Harness \
			mbuffer>=0:misc/mbuffer

USES=		gmake autoreconf perl5
USE_GITHUB=	yes
GH_ACCOUNT=	oetiker

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --libdir=${SITE_PERL}
CONFIGURE_ENV=	PERL5LIB=${SITE_PERL}
NO_ARCH=	yes

USE_RC_SUBR=	znapzend

pre-configure:
	@${REINPLACE_CMD} -e '/thirdparty\/Makefile/d' ${WRKSRC}/configure.ac

post-configure:
	@${REINPLACE_CMD} -e 's/thirdparty//g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
