PORTNAME=	sxml
PORTVERSION=	1.0.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.MysticWALL.COM/download/

MAINTAINER=	takefu@airport.fm
COMMENT=	Skimpy XML parsing and grafting library for C language
WWW=		http://www.MysticWALL.COM/software/sxml/index.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		tar:bzip2

do-test:
	cd ${BUILD_WRKSRC}/examples && ${MAKE} all

.include <bsd.port.mk>
