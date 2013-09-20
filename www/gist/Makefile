# Created by: Ricky E. <codeblock@eighthbit.net>
# $FreeBSD$

PORTNAME=	gist
PORTVERSION=	3.1.0
PORTREVISION=	3
CATEGORIES=	www net

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	A gist pastebin posting command

CONFLICTS=	p5-App-gist-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	defunkt
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	82ffb80

MAN1=		gist.1

USE_RUBY=	YES
NO_BUILD=	YES
PLIST_FILES=	bin/gist

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${RUBY_VER} < 1.9
RUN_DEPENDS+=	${DEPEND_RUBY_ICONV}
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gist ${PREFIX}/bin/gist
	${INSTALL_MAN} ${WRKSRC}/man/gist.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
