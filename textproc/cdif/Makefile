PORTNAME=	cdif
PORTVERSION=	2.14.20170401
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Word context visualizer of DIFF output

LICENSE=	GREPLE
LICENSE_NAME=	GREPLE License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${SITE_PERL}/Getopt/EX.pm:devel/p5-Getopt-EX

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	kaz-utashiro
GH_TAGNAME=	2f4de90
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	bin/cdif

post-extract:
	cd ${WRKSRC} && \
	    ${SED} -n "/^# COPYRIGHT/,//p" README.md > LICENSE

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/cdif

.include <bsd.port.mk>
