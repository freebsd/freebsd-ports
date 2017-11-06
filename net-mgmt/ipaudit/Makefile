# Created by: Ying-Chieh Chen <yinjieh@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	ipaudit
PORTVERSION=	1.1
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	ipaudit/ipaudit

MAINTAINER=	amutu@amutu.com
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
