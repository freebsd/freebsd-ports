# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hikidoc
PORTVERSION=	0.0.6
CATEGORIES=	textproc ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${RUBY_PKGNAMEPREFIX:S|${RUBY_SUFFIX}-||}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A text-to-HTML conversion tool for web writers

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SHEBANG_FILES=	bin/hikidoc
NO_STAGE=	yes

PORTDOCS=	NEWS NEWS.ja README README.ja \
		TextFormattingRules TextFormattingRules.ja

PLIST_FILES=	bin/hikidoc \
		%%RUBY_SITELIBDIR%%/hikidoc.rb

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
