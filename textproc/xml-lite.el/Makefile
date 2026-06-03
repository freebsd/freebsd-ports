PORTNAME=	xml-lite.el
PORTVERSION=	1.1
PORTREVISION=	29
PORTEPOCH=	1
CATEGORIES=	textproc elisp
MASTER_SITES=	http://dogbiscuit.org/mdub/software/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple XML-editing for GNU Emacs
WWW=		https://www.dogbiscuit.org/mdub/software/

LICENSE=	GPLv2+

USES=		emacs

CONFLICTS_INSTALL=	xml-lite.el-emacs_*

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=${WRKSRC}/${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/${PORTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
