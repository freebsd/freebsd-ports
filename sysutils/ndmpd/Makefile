PORTNAME=	ndmpd
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network Data Management Protocol daemon

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	iXsystems
GH_TAGNAME=	ffde7d1

PLIST_FILES=	sbin/ndmpd etc/ndmpd.conf.example

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ndmpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/ndmpd.conf \
		${STAGEDIR}${PREFIX}/etc/ndmpd.conf.example

.include <bsd.port.mk>
