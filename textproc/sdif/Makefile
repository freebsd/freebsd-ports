# $FreeBSD$

PORTNAME=	sdif
PORTVERSION=	2.8.20170401
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Side-by-side diff viewer for ANSI terminal

LICENSE=	GREPLE
LICENSE_NAME=	GREPLE License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${SITE_PERL}/Getopt/EX.pm:devel/p5-Getopt-EX

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	kaz-utashiro
GH_TAGNAME=	356575d
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	bin/sdif \
		%%SITE_PERL%%/App/sdif/colors.pm \
		%%SITE_PERL%%/App/sdif/osx_autocolor.pm

post-extract:
	cd ${WRKSRC} && \
	    ${SED} -n "/^## Copyright/,/^$$/p" sdif > LICENSE

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/lib && \
	    ${COPYTREE_SHARE} App ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}

.include <bsd.port.mk>
