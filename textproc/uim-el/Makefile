PORTNAME=	uim-el
PORTVERSION=	1.9.6
PORTREVISION=	1
CATEGORIES=	textproc
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	Emacs lisp for uim input method library
WWW=		https://github.com/uim/uim

LICENSE=	BSD3CLAUSE GPLv2+ GPLv3+ LGPL21+ PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	uim-el-agent:textproc/uim

USES=		autoreconf:build,2.69 emacs gettext gmake gnome iconv libtool \
		pathfix perl5 pkgconfig
USE_GNOME=	intltool
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	uim
GH_PROJECT=	uim

GNU_CONFIGURE=	yes

BUILD_WRKSRC=	${WRKSRC}/emacs
INSTALL_WRKSRC=	${WRKSRC}/emacs

CONFIGURE_ARGS?=--enable-maintainer-mode --enable-emacs \
		--with-lispdir=${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}
CONFIGURE_ENV=	EMACS="${EMACS_CMD}"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

DOCSDIR_JA=	${PREFIX}/share/doc/ja/uim-el
PLIST_SUB+=	DOCSDIR_JA="${DOCSDIR_JA:S,^${PREFIX}/,,}"

OPTIONS_DEFINE=	DOCS

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR_JA}
	${INSTALL_DATA} ${WRKSRC}/emacs/README ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/emacs/README.ja ${STAGEDIR}${DOCSDIR_JA}/README.ja

.include <bsd.port.mk>
