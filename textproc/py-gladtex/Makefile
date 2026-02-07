PORTNAME=	gladtex
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1
CATEGORIES=	textproc math www
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	LaTeX formula preprocessor for HTML files
WWW=		https://humenda.github.io/GladTeX/ \
		https://github.com/humenda/GladTeX/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	go-md2man:textproc/go-md2man

USES=		python tex
USE_GITHUB=	yes
GH_ACCOUNT=	humenda
GH_PROJECT=	GladTeX
USE_PYTHON=	autoplist distutils
USE_TEX=	dvipsk:run latex:run

CONFLICTS_INSTALL=	gladtex

NO_ARCH=	yes

PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

post-install:
	go-md2man -in ${WRKSRC}/manpage.md -out ${TMPDIR}/${PORTNAME}.1
	${INSTALL_MAN} ${TMPDIR}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
