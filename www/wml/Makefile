# Created by: Ralf S. Engelschall <rse@engelschall.com>
# $FreeBSD$

PORTNAME=	wml
PORTVERSION=	2.0.12
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	www lang
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=thewml

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Website META Language, webdesign toolkit for HTML generation

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png
RUN_DEPENDS=	\
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-Bit-Vector>=5.2:${PORTSDIR}/math/p5-Bit-Vector \
		p5-File-PathConvert>0:${PORTSDIR}/devel/p5-File-PathConvert \
		p5-Image-Size>=2.6:${PORTSDIR}/graphics/p5-Image-Size \
		p5-Term-ReadKey>=2.11:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-HTML-Clean>0:${PORTSDIR}/www/p5-HTML-Clean \
		p5-GD>0:${PORTSDIR}/graphics/p5-GD
BUILD_DEPENDS=	lynx:${PORTSDIR}/www/lynx \
		${RUN_DEPENDS}

GNU_CONFIGURE=	yes
USES=		gettext perl5 gmake
USE_PERL5=	run build patch
CONFIGURE_ARGS=	--with-perl=${PERL5} --with-catdir=man \
		--prefix=${PREFIX}

.include <bsd.port.pre.mk>

.if ${PERL_VER} >= 5.18
BROKEN=		Does not build with Perl 5.18 or above
.endif

post-patch:
	@${PERL5} -pi -e 's!^(\s+have_\S+)=\S+!\1=1!' \
		${WRKSRC}/wml_common/Makefile.in

do-configure:
	@[ -f ${CONFIGURE_COOKIE}] || (cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS})

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test:
	@cd ${WRKSRC} && ${MAKE_CMD} test

.include <bsd.port.post.mk>
