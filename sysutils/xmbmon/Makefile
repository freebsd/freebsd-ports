# Ports collection makefile for:	xmbmon
# Date created:				2001/08/30
# Whom:					kaz@kobe1995.net (NAKAMURA Kauzushi)
#
# $FreeBSD$
#

PORTNAME=	xmbmon
PORTVERSION=	201
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/
.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
.endif
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	kaz@kobe1995.net

GNU_CONFIGURE=	yes
.if defined(WITHOUT_X11)
MAKE_ARGS+=	DOCSDIR='$(DOCSDIR)' INSTALL_DATA='$(INSTALL_DATA)'
PLIST_SUB=	X11_ONLY="@comment "
.else
USE_XLIB=	yes
MAKE_ARGS+=	DOCSDIR='$(DOCSDIR)' INSTALL_DATA='$(INSTALL_DATA)'
PLIST_SUB=	X11_ONLY=""
.endif

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Definable build options"
	@${ECHO_CMD} "-----------------------"
	@${ECHO_CMD} "WITHOUT_X11	- Self explanatory"
	@${ECHO_CMD} ""

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}; ${MAKE} ${MAKE_ARGS} install-doc)
.endif

.include <bsd.port.mk>
