# New ports collection makefile for:	Ruby-xmlparser
# Date created:		9 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xmlparser
PORTVERSION=	0.6.5
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.yoshidam.net/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${PERL_ARCHLIB}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv \
		${PERL_ARCHLIB}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-Parser
# to utilize encoding maps included in p5-XML-Parser

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

PERL_ARCHLIB=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-perl-enc-map=${PERL_ARCHLIB}/XML/Parser/Encodings
INSTALL_TARGET=	site-install

post-extract:
	${RM} -r ${WRKSRC}/samples/expat-1.2

post-patch:
	${RUBY} -i -pe 'gsub /%%PREFIX%%/, "${PREFIX}"' ${WRKSRC}/lib/wget.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
