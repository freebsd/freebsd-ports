# $FreeBSD$

PORTNAME=	greple
PORTVERSION=	8.3304
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Grep with multiple keywords

LICENSE=	GREPLE
LICENSE_NAME=	GREPLE License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	p5-Getopt-EX>=1.15.0,1:devel/p5-Getopt-EX

USES=		perl5 shebangfix
USE_PERL5=	run
USE_GITHUB=	yes
GH_ACCOUNT=	kaz-utashiro
GH_TAGNAME=	5ad6491

SHEBANG_FILES=	bin/${PORTNAME}
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
