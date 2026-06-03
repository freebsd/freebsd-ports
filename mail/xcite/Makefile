PORTNAME=	xcite
PORTVERSION=	1.60
PORTREVISION=	30
CATEGORIES=	mail elisp
MASTER_SITES=	https://www.gentei.org/~yuuji/software/
DISTNAME=	${PORTNAME}.el
EXTRACT_SUFX=	# empty

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Exciting Cite for any Mail/News reading modes on Emacs
WWW=		https://www.gentei.org/~yuuji/software/

USES=		emacs

NO_WRKSUBDIR=	yes

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	.

CONFLICTS_INSTALL=	xcite-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/${DISTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
