# New ports collection makefile for:        latte
# Date created:         15 August 1999
# Whom:                 Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	latte
PORTVERSION=	2.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.latte.org/ \
		ftp://ftp.brasslantern.com/pub/zanshin/latte/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple language for marking up text in a very expressive way

USE_BISON=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	213
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-shared
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
INSTALLS_SHLIB=	yes

INFO=		latte liblatte

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
USE_GCC=	3.3
.endif

post-extract:
	-@${RM} ${WRKSRC}/getopt*

post-install:
	@${LN} -sf latte-html ${PREFIX}/bin/latte
	${INSTALL_DATA} ${WRKSRC}/latte.el ${PREFIX}/share/emacs/site-lisp
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC} --exclude "*Makefile*" -cf - tests | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
