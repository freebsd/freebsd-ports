# New ports collection makefile for:   xdvik
# Date created:        26 Feb 1998
# Whom:                Kentaro Inagaki <JBD01226@niftyserve.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xdvik
PORTVERSION=	20a
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.tug.org/ftp/historic/systems/dviware/xdvik/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X

RUN_DEPENDS=	mf:${PORTSDIR}/print/tex

USE_XLIB=	yes
GNU_CONFIGURE=YES
#CONFIGURE_ARGS=--enable-shared=yes
USE_GMAKE=YES

MAN1=xdvi.1 gsftopk.1

pre-build:
	(cd ${WRKSRC} ; ${FIND} . -name '*.orig' -exec ${RM} -f {} \;)

do-install:
	(cd ${WRKSRC}/xdvik ; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

post-install:
	${MKDIR} ${PREFIX}/share/doc/xdvi
	${INSTALL_DATA} ${WRKSRC}/xdvik/xdvi.FAQ ${PREFIX}/share/doc/xdvi
	${INSTALL_DATA} ${WRKSRC}/xdvik/README ${PREFIX}/share/doc/xdvi
	${INSTALL_DATA} ${WRKSRC}/xdvik/ChangeLog ${PREFIX}/share/doc/xdvi

.include <bsd.port.mk>
