# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xcite
PORTVERSION=	1.60
PORTREVISION=	12
CATEGORIES=	mail elisp
MASTER_SITES=	https://www.gentei.org/~yuuji/software/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}.el
EXTRACT_SUFX=	# empty

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Exciting Cite for any Mail/News reading modes on Emacs

USES=		emacs

NO_WRKSUBDIR=	yes

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	.

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/${DISTNAME} \
		${EMACS_VERSION_SITE_LISPDIR}/${DISTNAME}c

do-build:
	@(cd ${WRKSRC} && ${EMACS_CMD} -batch -q -no-site-file -no-init-file \
		-f batch-byte-compile ${DISTNAME})

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}c \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.mk>
