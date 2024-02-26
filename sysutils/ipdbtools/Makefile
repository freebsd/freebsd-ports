PORTNAME=	ipdbtools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	cyclaero@gmail.com
COMMENT=	Tools for IP based Geo-blocking and Geo-routing
WWW=		https://cyclaero.github.io/ipdb/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	cyclaero
GH_PROJECT=	ipdb

PLIST_FILES=	bin/ipup \
		bin/ipdb \
		bin/ipdb-update.sh \
		share/man/man1/ipdbtools.1.gz \
		share/man/man1/ipup.1.gz \
		share/man/man1/ipdb.1.gz \
		share/man/man1/ipdb-update.sh.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|man/man1|share/man/man1|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
