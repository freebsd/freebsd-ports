PORTNAME=	puppet-mode.el
PORTVERSION=	0.2
PORTREVISION=	22
CATEGORIES=	sysutils elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Simple mode for editing puppet manifests
WWW=		https://github.com/puppetlabs/puppet-syntax-emacs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs
GH_PROJECT=	puppet-syntax-emacs
GH_TAGNAME=	be5d708

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/puppet-mode.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/puppet-mode.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
