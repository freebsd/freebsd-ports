# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	cowpatty
PORTVERSION=	4.6
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://www.willhackforsushi.com/code/cowpatty/${PORTVERSION}/ \
		http://mcx2.org/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Brute-force dictionary attack against WPA-PSK

LICENSE=	GPLv2

PORTDOCS=	FAQ README
SUB_FILES=	pkg-message
MAKE_JOBS_UNSAFE=	yes
OPTIONS_DEFINE=	DOCS

USE_OPENSSL=	yes

PLIST_FILES=	bin/cowpatty bin/genpmk

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
