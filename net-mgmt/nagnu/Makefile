PORTNAME=	nagnu
PORTVERSION=	1.1.3
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	fredrik@min-hemsida.net
COMMENT=	Nagios dashboard
WWW=		https://github.com/frlen/nagnu

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	frlen
PLIST_FILES=	bin/nagnu \
		share/man/man8/nagnu.8.gz \
		share/examples/nagnu/nagnu.conf.sample

GNU_CONFIGURE=	yes
CFLAGS+=	-fcommon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nagnu ${STAGEDIR}${PREFIX}/bin

	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/nagnu
	${INSTALL_DATA} ${WRKSRC}/nagnu.conf.sample \
		${STAGEDIR}${PREFIX}/share/examples/nagnu/nagnu.conf.sample

	${INSTALL_MAN} ${WRKSRC}/docs/nagnu.8 \
		${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
