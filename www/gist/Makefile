PORTNAME=	gist
PORTVERSION=	6.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	www net

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Gist pastebin posting command
WWW=		https://github.com/defunkt/gist/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.MIT

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		ruby:run
USE_GITHUB=	yes
GH_ACCOUNT=	defunkt

CONFLICTS=	p5-App-gist py*-python-gist yorick # bin/gist

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/gist \
		share/man/man1/gist.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/build/gist

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/build/gist ${STAGEDIR}${PREFIX}/bin/gist
	${INSTALL_MAN} ${WRKSRC}/build/gist.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
