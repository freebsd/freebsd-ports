PORTNAME=	cowpatty
PORTVERSION=	4.8
CATEGORIES=	net-mgmt security

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Brute-force dictionary attack against WPA-PSK

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ssl

USE_GITHUB=	YES
GH_ACCOUNT=	joswr1ght

PORTDOCS=	FAQ README
SUB_FILES=	pkg-message
MAKE_JOBS_UNSAFE=	yes
OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/cowpatty bin/genpmk

post-patch:
	${REINPLACE_CMD} \
		-e "s|\(-DOPENSSL\)|\1 -I${OPENSSLINC} -L${OPENSSLLIB} |g" \
		${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
