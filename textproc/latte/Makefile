# New ports collection makefile for:        latte
# Date created:         15 August 1999
# Whom:                 Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	latte
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.latte.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple language for marking up text in a very expressive way

USE_BISON=	build
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:213 libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-shared
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
USE_LDCONFIG=	yes

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
	${MKDIR} ${PREFIX}/lib/xemacs/site-lisp
	${LN} -sf ${PREFIX}/share/emacs/site-lisp/latte.el \
		  ${PREFIX}/lib/xemacs/site-lisp
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC} --exclude "*Makefile*" -cf - tests | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
