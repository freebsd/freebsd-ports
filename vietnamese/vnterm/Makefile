# ex:ts=8
# Ports collection makefile for:    vnterm
# Date created:         Sat July 20, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	vnterm
PORTVERSION=	3.4	#11.6.5.1
CATEGORIES=	vietnamese x11
MASTER_SITES=	ftp://ftp.x.org/pub/R6.5.1/tars/
DISTNAME=	xorg-1

MAINTAINER=	obrien@FreeBSD.org

USE_IMAKE=	yes

.include <bsd.port.pre.mk>

BUILD_DEPENDS=  ${LOCALBASE}/lib/libviqr.a:${PORTSDIR}/vietnamese/libviet
RUN_DEPENDS=	${PREFIX}/lib/X11/fonts/vietnamese/fonts.dir:${PORTSDIR}/vietnamese/vnxfonts
.if ${XFREE86_VERSION} == 4
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - xc/programs/xterm
WRKSRC=		${WRKDIR}/xc/programs/xterm
XMKMF=		xmkmf
MAN1=		vnterm.1
CFLAGS+=	-I${PREFIX}/include/viet
CFLAGS+=	-D_POSIX_SOURCE

post-patch:
	@${CP} -p ${FILESDIR}/vnvars.* ${WRKSRC}

pre-build:
	${LN} -f ${WRKSRC}/XTerm.ad ${WRKSRC}/VNTerm.ad
	${CP} -p ${FILESDIR}/vnterm.1V ${WRKSRC}/vnterm.man

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/VNterm.sh ${PREFIX}/bin/VNterm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/vnterm \
		&& ${CHMOD} a+rx ${PREFIX}/share/doc/vnterm
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/vnterm
.endif

.include <bsd.port.post.mk>
