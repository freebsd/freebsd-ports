# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	growl
PORTVERSION=	3.0
CATEGORIES=	net ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	${PKGNAMEPREFIX:S|${RUBY_SUFFIX}||}${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PKGNAMEPREFIX:S|${RUBY_SUFFIX}||}${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${RUBY_PKGNAMEPREFIX:S|${RUBY_SUFFIX}-||}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A pure-ruby growl notifier

USE_RUBY=	yes
NO_BUILD=	yes

RUBY_SHEBANG_FILES=	bin/growl lib/ruby-growl.rb
PLIST_FILES=	bin/growl \
		%%RUBY_SITELIBDIR%%/ruby-growl.rb

PORTDOCS=	History.txt README.txt
DOCSDIR=	${RUBY_MODDOCDIR}

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/growl ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/lib/ruby-growl.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
