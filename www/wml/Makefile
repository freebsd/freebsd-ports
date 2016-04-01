# Created by: Ralf S. Engelschall <rse@engelschall.com>
# $FreeBSD$

PORTNAME=	wml
PORTVERSION=	2.0.12
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	www lang
MASTER_SITES=	SF/thewml

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Website META Language, webdesign toolkit for HTML generation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png
RUN_DEPENDS=	\
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-Bit-Vector>=5.2:math/p5-Bit-Vector \
		p5-File-PathConvert>0:devel/p5-File-PathConvert \
		p5-Image-Size>=2.6:graphics/p5-Image-Size \
		p5-Term-ReadKey>=2.11:devel/p5-Term-ReadKey \
		p5-HTML-Clean>0:www/p5-HTML-Clean \
		p5-GD>0:graphics/p5-GD
BUILD_DEPENDS=	lynx:www/lynx \
		${RUN_DEPENDS}

INFO=		logo-apache logo-freebsd logo-gimp logo-htdig logo-linux logo-netbsd \
		logo-openbsd logo-php logo-php3 logo-vim logo-wml logo-xemacs
INFO_PATH=	lib/wml/data/logos
GNU_CONFIGURE=	yes
USES=		gettext perl5 gmake
USE_PERL5=	run build patch
CONFIGURE_ARGS=	--with-perl=${PERL5} --with-catdir=man \
		--prefix=${PREFIX}

.include <bsd.port.pre.mk>

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
