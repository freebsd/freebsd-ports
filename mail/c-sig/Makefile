PORTNAME=	c-sig
PORTVERSION=	3.8.0.1
PORTREVISION=	20
CATEGORIES=	mail elisp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Signature insertion tool for Emacs
WWW=		https://github.com/yasuhirokimura/c-sig

LICENSE=	GPLv2+

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	yasuhirokimura

CONFLICTS_INSTALL=	c-sig-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

MAKE_ENV+=	EMACS=${EMACS_CMD} LISPDIR=${LISPDIR}
LISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/c-sig.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in c-sig-eng.faq c-sig-eng.man c-sig-jp.faq c-sig-jp.man
	${INSTALL_MAN} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
