# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
# $FreeBSD$

PORTNAME=	sendEmail
PORTVERSION=	1.56
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://caspian.dotconf.net/menu/Software/SendEmail/ \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight, completely command line based, SMTP email agent

LICENSE=	GPLv2+

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/sendEmail
PORTDOCS=	CHANGELOG README TODO

OPTIONS_DEFINE=	SSL DOCS
SSL_DESC=	SSL/TLS support for communicating with the SMTP server

SSL_RUN_DEPENDS=p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
