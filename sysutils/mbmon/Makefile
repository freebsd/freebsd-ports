# Ports collection makefile for:	xmbmon
# Date created:				2001/08/30
# Whom:					kaz@kobe1995.net (NAKAMURA Kauzushi)
#
# $FreeBSD$
#

PORTNAME=	xmbmon
PORTVERSION=	205
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/xmbmon/
.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
.endif
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	kaz@kobe1995.net
COMMENT=	X/tty motherboard monitor for LM78/79, W8378x, AS99127F, VT82C686 and ADM9240

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
.if defined(WITHOUT_X11)
PLIST_SUB=	X11_ONLY="@comment "
.else
USE_XLIB=	yes
PLIST_SUB=	X11_ONLY=""
.endif

MAKE_ARGS+=	DOCSDIR='${DOCSDIR}' INSTALL_DATA='${INSTALL_DATA}' PREFIX='${PREFIX}'

MAN1=		xmbmon.1x mbmon.1

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
BROKEN=		"Does not compile on !i386 and !amd64"
.endif

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Definable build options"
	@${ECHO_CMD} "-----------------------"
	@${ECHO_CMD} "WITHOUT_X11	- Self explanatory"
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} -e 's+/usr/share/doc/mbmon+${DOCSDIR}+' ${WRKSRC}/mbmon.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}; ${MAKE} ${MAKE_ARGS} install-man install-doc)
.endif

.include <bsd.port.post.mk>
