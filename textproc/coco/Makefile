# New ports collection makefile for:   coco
# Date created:     2 December 2001
# Whom:             Teruaki Ata <PFA03027@nifty.ne.jp>
#
# $FreeBSD$
#

PORTNAME=       coco
PORTVERSION=    ${MULE_VERSION}
PORTREVISION=	1
CATEGORIES=     textproc
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/ \
		ftp://ftp.jaist.ac.jp/pub/GNU/mule/ \
		http://www.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/mule/
DISTFILES=	mule-${MULE_VERSION}-${EMACS_VERSION}.tar.gz \
		mule-${MULE_VERSION}-${EMACS_VERSION}.patch-981002.tar.gz

MAINTAINER=     PFA03027@nifty.ne.jp
COMMENT=	Code converter for any of Mule's code

MAN1=           coco.1 m2ps.1
MANCOMPRESSED=  no

WRKSRC=		${WRKDIR}/mule-${MULE_VERSION}-${EMACS_VERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
EMACS_PREFIX=	mule
MULE_VERSION=	2.3
EMACS_VERSION=	19.34

INSTALL_TARGET=	install-coco install-m2ps

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

# extract patches for mule2.3 based on emacs-19.34b
post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/mule-${MULE_VERSION}-${EMACS_VERSION}.patch-981002.tar.gz ${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	${CP} ${FILESDIR}/unexfreebsd.c ${WRKSRC}/src

# apply patches to mule2.3 before appling FreeBSD patches
pre-patch:
	cd ${WRKSRC}; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/Mule-${MULE_VERSION}-${EMACS_VERSION}.patch

# delete dust files before build
pre-build:
	${FIND} ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	${RM} -f ${WRKSRC}/etc/DOC* ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-${EMACS_VERSION}.*

.include <bsd.port.post.mk>
