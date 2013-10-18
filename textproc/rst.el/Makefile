# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	rst.el
PORTVERSION=	6390
PORTREVISION=	8
CATEGORIES=	textproc elisp
MASTER_SITES=	http://svn.berlios.de/viewcvs/docutils/trunk/docutils/tools/editors/emacs/
PKGNAMESUFFIX=	-${EMACS_NAME}
DISTNAME=	rst.el\?revision=${PORTVERSION}
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ReStructuredText Support for Emacs

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

USE_EMACS=	yes

BROKEN=		checksum mismatch

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKSRC}/rst.el

ELISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if (${EMACS_NAME} == "xemacs")
BUILD_DEPENDS+=	${LOCALBASE}/lib/xemacs/xemacs-packages/lisp/xemacs-base/compile.el:${PORTSDIR}/editors/xemacs-packages
.endif

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -q -f batch-byte-compile ${PORTNAME}

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}c ${ELISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
