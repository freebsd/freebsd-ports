# Created by: Ricky E. <codeblock@eighthbit.net>
# $FreeBSD$

PORTNAME=	gist
PORTVERSION=	4.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www net

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Gist pastebin posting command

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.MIT

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

CONFLICTS=	p5-App-gist-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	defunkt

USE_RUBY=	YES
RUBY_NO_BUILD_DEPENDS=	YES
NO_BUILD=	YES
NO_ARCH=	yes

PLIST_FILES=	bin/gist \
		man/man1/gist.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/build/gist

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/build/gist ${STAGEDIR}${PREFIX}/bin/gist
	${INSTALL_MAN} ${WRKSRC}/build/gist.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
