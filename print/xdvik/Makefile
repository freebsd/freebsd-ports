# New ports collection makefile for:   xdvik
# Version required:    20
# Date created:        26 Feb 1998
# Whom:                Kentaro Inagaki <JBD01226@niftyserve.ne.jp>
#
# $Id$
#

DISTNAME=	xdvik-20a
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ipc.chiba-u.ac.jp/pub/pub.yamaga/xdvik-20/ \
		${MASTER_SITE_LOCAL}

MAINTAINER=	JBD01226@niftyserve.ne.jp

RUN_DEPENDS=    mf:${PORTSDIR}/print/tex

GNU_CONFIGURE=YES
#CONFIGURE_ARGS=--enable-shared=yes
USE_GMAKE=YES

MAN1=xdvi.1 gsftopk.1

pre-build:
	(cd ${WRKSRC} ; find . -name '*.orig' -exec ${RM} -f {} \;)

do-install:
	(cd ${WRKSRC}/xdvik ; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

post-install:
	${MKDIR} ${PREFIX}/share/doc/xdvi
	${INSTALL_DATA} ${WRKSRC}/xdvik/xdvi.FAQ ${PREFIX}/share/doc/xdvi
	${INSTALL_DATA} ${WRKSRC}/xdvik/README ${PREFIX}/share/doc/xdvi
	${INSTALL_DATA} ${WRKSRC}/xdvik/ChangeLog ${PREFIX}/share/doc/xdvi

.include <bsd.port.mk>
