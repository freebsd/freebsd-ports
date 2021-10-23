# Created by: KIMURA Yasuhiro <yasu@utahime.org>

PORTNAME=	c-sig
PORTVERSION=	3.8.0.1
PORTREVISION=	7
CATEGORIES=	mail elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Signature insertion tool for Emacs

LICENSE=	GPLv2+

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	yasuhirokimura
NO_ARCH=	yes

MAKE_ENV+=	EMACS=${EMACS_CMD} LISPDIR=${LISPDIR}
LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in c-sig-eng.faq c-sig-eng.man c-sig-jp.faq c-sig-jp.man
	${INSTALL_MAN} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
