PORTNAME=	yaml.el
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.3
CATEGORIES=	textproc elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	YAML parser in Elisp

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	zkry

NO_ARCH=	yes
PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/yaml.el \
		${EMACS_VERSION_SITE_LISPDIR}/yaml.elc

do-build:
	(cd ${WRKSRC} \
	&& ${EMACS_CMD} -Q -batch -L . -f batch-byte-compile yaml.el)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} yaml.el* \
	    ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR})

.include <bsd.port.mk>
