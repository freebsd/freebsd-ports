# $FreeBSD$

PORTNAME=	nagnu
PORTVERSION=	1.1.2
CATEGORIES=	net-mgmt

MAINTAINER=	fredrik@min-hemsida.net
COMMENT=	Nagios dashboard

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libncurses.so:devel/ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	frlen
PLIST_FILES=	bin/nagnu \
		man/man8/nagnu.8.gz \
		share/examples/nagnu/nagnu.conf.sample

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nagnu ${STAGEDIR}${PREFIX}/bin

	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/nagnu
	${INSTALL_DATA} ${WRKSRC}/nagnu.conf.sample \
		${STAGEDIR}${PREFIX}/share/examples/nagnu/nagnu.conf.sample

	${INSTALL_MAN} ${WRKSRC}/docs/nagnu.8 \
		${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
