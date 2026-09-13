PORTNAME=	google-translate
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0-65
DISTVERSIONSUFFIX=	-g47c5719
CATEGORIES=	textproc elisp

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Emacs interface to Google Translate
WWW=		https://github.com/atykhonov/google-translate

LICENSE=	GPLv2+

USE_GITHUB=	yes
GH_ACCOUNT=	atykhonov

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

ELISPDIR=	share/emacs/site-lisp/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/${ELISPDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
