PORTNAME=	ipaudit
PORTVERSION=	1.1
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	SF/ipaudit/ipaudit

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP traffic summarizer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS
GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/ipaudit.conf.sample ${STAGEDIR}${PREFIX}/etc

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
