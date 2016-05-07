# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uim-el
PORTVERSION=	1.8.6
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	uim-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	Emacs lisp for uim input method library

PROJECTHOST=	uim
CONFLICTS?=	uim-el-xemacs21-mule-[0-9]* \
		uim-el-emacs22-[0-9]* \
		uim-el-emacs21-[0-9]*

RUN_DEPENDS=	uim-el-agent:textproc/uim

OPTIONS_DEFINE=	DOCS

USES=		gettext-tools gmake iconv perl5 tar:bzip2
USE_PERL5=	build
USE_GNOME=	intltool
USE_EMACS=	yes
GNU_CONFIGURE=	yes

BUILD_WRKSRC=	${WRKSRC}/emacs
INSTALL_WRKSRC=	${WRKSRC}/emacs

CONFIGURE_ARGS?=--enable-emacs --with-lispdir=${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}
CONFIGURE_ENV=	EMACS="${EMACS_CMD}"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

DOCSDIR_JA=	${PREFIX}/share/doc/ja/uim-el
PLIST_SUB+=	DOCSDIR_JA="${DOCSDIR_JA:S,^${PREFIX}/,,}"

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR_JA}
	${INSTALL_DATA} ${WRKSRC}/emacs/README ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/emacs/README.ja ${STAGEDIR}${DOCSDIR_JA}/README.ja

.include <bsd.port.mk>
