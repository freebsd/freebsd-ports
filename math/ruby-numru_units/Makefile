# Created by: Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
# $FreeBSD$

PORTNAME=	numru_units
PORTVERSION=	1.7
CATEGORIES=	math ruby
MASTER_SITES=	http://ruby.gfd-dennou.org/products/numru-units/release/ \
		http://dennou-h.gfd-dennou.org/library/ruby/products/numru-units/release/ \
		http://dennou-q.gfd-dennou.org/library/ruby/products/numru-units/release/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	numru-units-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	A class to handle units of physical quantities for Ruby

OPTIONS_DEFINE=	DOCS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_RUBY=	yes
NO_BUILD=	yes

DOCS=		ChangeLog LICENSE.txt doc/units.html doc/units.rd

do-install:
	@cd ${WRKSRC}/ && ${RUBY} ./install.rb -d ${STAGEDIR}${RUBY_SITELIBDIR}
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}
.endfor

.include <bsd.port.mk>
