# New ports collection makefile for:	PARI
# Date created:		19 January 1999
# Whom:	Yoshiaki UCHIKAWA <yoshiaki@kt.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	pari
PORTVERSION=	${MAJOR_VERSION}.${MINOR_VERSION}.${REV_VERSION}
CATEGORIES=	math
MASTER_SITES=	http://pari.math.u-bordeaux.fr/pub/pari/unix/
DISTNAME=	pari-${MAJOR_VERSION}.${MINOR_VERSION}.${REV_VERSION}

MAINTAINER=	yoshiaki@kt.rim.or.jp
COMMENT=	Mathmatics library and advanced calculator package

CONFLICTS=	pari-2.2.*

EXTRACT_SUFX=	.tgz
NO_LATEST_LINK=	yes
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	--prefix=${PREFIX} --share-prefix=${PREFIX}/share

#USE_GMAKE=	yes
MAKE_ARGS=	gp
PLIST_SUB=	MAJOR_VERSION=${MAJOR_VERSION} MINOR_VERSION=${MINOR_VERSION} REV_VERSION=${REV_VERSION}

MAJOR_VERSION=	2
MINOR_VERSION=	1
REV_VERSION=	7

MAN1=		gp.1 gphelp.1 tex2mail.1
MLINKS=		gp.1 pari.1

.include <bsd.port.pre.mk>

HAVE_EMACS!=	${WHICH} emacs || ${ECHO} nope
.if ${HAVE_EMACS} != "nope"
PLIST=		${PKGDIR}/pkg-plist.emacs
.endif

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|"${CFLAGS}"|' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
