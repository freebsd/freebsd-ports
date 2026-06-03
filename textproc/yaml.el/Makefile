PORTNAME=	yaml.el
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.3
CATEGORIES=	textproc elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	YAML parser in Elisp
WWW=		https://github.com/zkry/yaml.el

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

#TODO: Handle TEST_DEPENDS in Mk/Uses/emacs.mk
#TEST_DEPENDS=	emacs:editors/emacs

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	zkry

CONFLICTS_INSTALL=	yaml.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/${PORTNAME}/yaml.el

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	(cd ${WRKSRC} && ${INSTALL_DATA} yaml.el \
	    ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME})

#TODO: Handle TEST_DEPENDS in Mk/Uses/emacs.mk
#do-test:
#	(cd ${WRKSRC} \
#	&& ${EMACS_CMD} -Q -batch -L . -l ert -l yaml.el \
#	-l yaml-tests.el -f ert-run-tests-batch-and-exit)

.include <bsd.port.mk>
