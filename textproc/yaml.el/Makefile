PORTNAME=	yaml.el
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	textproc elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	YAML parser in Elisp
WWW=		https://github.com/zkry/yaml.el

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

do-test:
	(cd ${WRKSRC} \
	&& ${EMACS_CMD} -Q -batch -L . -l ert -l yaml.el \
	-l yaml-tests.el -f ert-run-tests-batch-and-exit)

.include <bsd.port.mk>
