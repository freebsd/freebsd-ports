# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	xmlparser
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.yoshidam.net/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby module to access James Clark XML Parser ToolKit ("expat")

BROKEN=		unfetchable

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser
LIB_DEPENDS=	libexpat.so:textproc/expat2
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/uconv.so:japanese/ruby-uconv \
		p5-XML-Parser>=0:textproc/p5-XML-Parser
# to utilize encoding maps included in p5-XML-Parser

USES=		perl5
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-perl-enc-map=${SITE_ARCH}/XML/Parser/Encodings
INSTALL_TARGET=	site-install
MAKE_ARGS=	INSTALL_PROG="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

OPTIONS_DEFINE=	DOCS

post-extract:
	${FIND} ${WRKSRC} -name CVS -type d -exec ${RM} -r {} ';' -prune

post-patch:
	${RUBY} -i -pe 'gsub /%%PREFIX%%/, "${PREFIX}"' ${WRKSRC}/lib/wget.rb

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

.include <bsd.port.mk>
