PORTNAME=	doc-mode.el
PORTVERSION=	1.1
PORTREVISION=	34
CATEGORIES=	textproc elisp
MASTER_SITES=	SF/xpt/doc-mode/doc-mode-${PORTVERSION}
DISTNAME=	doc-mode-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Asciidoc fontlocking for emacs
WWW=		https://xpt.sourceforge.net/tools/doc-mode/

USES=		emacs tar:tgz

CONFLICTS_INSTALL=	doc-mode.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc-mode.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/

.include <bsd.port.mk>
