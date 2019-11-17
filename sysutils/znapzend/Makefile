# $FreeBSD$

PORTNAME=	znapzend
PORTVERSION=	0.19.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ZnapZend is a ZFS centric backup tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mbuffer>=0:misc/mbuffer \
		p5-IO-Pipely>=0:devel/p5-IO-Pipely \
		p5-Mojo-IOLoop-ForkCall>=0.17:www/p5-Mojo-IOLoop-ForkCall \
		p5-Mojolicious>=7.15:www/p5-Mojolicious \
		p5-Pod-Simple>=0:textproc/p5-Pod-Simple \
		p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils \
		p5-Test-Harness>=0:devel/p5-Test-Harness
RUN_DEPENDS=	mbuffer>=0:misc/mbuffer \
		p5-IO-Pipely>=0:devel/p5-IO-Pipely \
		p5-Mojo-IOLoop-ForkCall>=0.17:www/p5-Mojo-IOLoop-ForkCall \
		p5-Mojolicious>=7.15:www/p5-Mojolicious \
		p5-Pod-Simple>=0:textproc/p5-Pod-Simple \
		p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils \
		p5-Test-Harness>=0:devel/p5-Test-Harness

USES=		autoreconf gmake perl5
USE_GITHUB=	yes
GH_ACCOUNT=	oetiker

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${SITE_PERL} \
		--prefix=${PREFIX}
CONFIGURE_ENV=	PERL5LIB=${SITE_PERL}
NO_ARCH=	yes

USE_RC_SUBR=	znapzend

pre-configure:
	@${REINPLACE_CMD} -e '/thirdparty\/Makefile/d' ${WRKSRC}/configure.ac

post-configure:
	@${REINPLACE_CMD} -e 's/thirdparty//g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
