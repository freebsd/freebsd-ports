# $FreeBSD$

PORTNAME=	wml
PORTVERSION=	2.0.12
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	www lang
MASTER_SITES=	MASTER_SITE_LOCAL

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Website META Language, webdesign toolkit for HTML generation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}	\
		lynx:www/lynx \
		p5-Module-CoreList>=0:devel/p5-Module-CoreList
LIB_DEPENDS=	libpng.so:graphics/png
RUN_DEPENDS=	p5-Bit-Vector>=7.4:math/p5-Bit-Vector		    \
		p5-File-PathConvert>=0.9:devel/p5-File-PathConvert  \
		p5-GD>=2.68:graphics/p5-GD			    \
		p5-HTML-Clean>=0.8:www/p5-HTML-Clean		    \
		p5-Image-Size>=3.300:graphics/p5-Image-Size	    \
		p5-Term-ReadKey>=2.37:devel/p5-Term-ReadKey	    \
		p5-XML-Parser>=2.44:textproc/p5-XML-Parser

USES=		gettext gmake perl5
USE_PERL5=	build patch run

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/var \
		--with-catdir=man --with-perl=${PERL}

INFO=		logo-apache logo-freebsd logo-gimp logo-htdig logo-linux \
		logo-netbsd logo-openbsd logo-php logo-php3 logo-vim logo-wml logo-xemacs
INFO_PATH=	lib/wml/data/logos

post-patch:
	${CP} ${FILESDIR}/extra-wml__aux_freetable_freetable.src \
	  ${WRKSRC}/wml_aux/freetable/freetable.src
	${PERL} -pi -e 's!^(\s+have_\S+)=\S+!\1=1!' \
	  ${WRKSRC}/wml_common/Makefile.in

do-configure:
	(cd ${WRKSRC} && ${SH} configure ${CONFIGURE_ARGS})

.include <bsd.port.mk>
