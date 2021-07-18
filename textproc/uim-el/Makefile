# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>

PORTNAME=	uim-el
PORTVERSION=	1.8.9.b.20210104
CATEGORIES=	textproc
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
#DISTNAME=	uim-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT?=	Emacs lisp for uim input method library

LICENSE=	BSD3CLAUSE GPLv2+ GPLv3+ LGPL21+ PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	uim-el-agent:textproc/uim

USES=		autoreconf:build emacs gettext gmake gnome iconv libtool pathfix perl5 pkgconfig
USE_GNOME=	intltool
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	uim
GH_PROJECT=	uim
GH_TAGNAME=	d1ac9d9

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
	cd ${WRKSRC} && ./autogen.sh

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR_JA}
	${INSTALL_DATA} ${WRKSRC}/emacs/README ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/emacs/README.ja ${STAGEDIR}${DOCSDIR_JA}/README.ja

.include <bsd.port.mk>
