# $FreeBSD$

PORTNAME=	greple
PORTVERSION=	7.1.20170401
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Grep with multiple keywords

LICENSE=	GREPLE
LICENSE_NAME=	GREPLE License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${SITE_PERL}/Getopt/EX.pm:devel/p5-Getopt-EX

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	bin/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	kaz-utashiro
GH_TAGNAME=	5ad6491
NO_BUILD=	yes
NO_ARCH=	yes

post-extract:
	cd ${WRKSRC} && \
	    ${SED} -n "/^# LICENSE/,//p" README.md > LICENSE

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_SCRIPT} bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/lib && \
	    ${COPYTREE_SHARE} App ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}

.include <bsd.port.mk>
