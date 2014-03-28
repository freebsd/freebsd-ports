# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	reduce
PORTVERSION=	20110414
CATEGORIES=	math lang
MASTER_SITES=	SF/${PORTNAME}-algebra/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	giffunip@tutopia.com
COMMENT=	Portable general-purpose computer algebra system (CSL version)

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

USES=		gmake tar:bzip2
USE_XORG=	xext x11 xft
USE_GNOME=	lthack ltverhack

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-csl
ALL_TARGET=

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

HMAN1=	redcsl.1

.if ${ARCH} == "amd64"
TARGET_SDIR=	x86_64-unknown-${OPSYS:L}${OSREL}
.else
TARGET_SDIR=	${ARCH}-unknown-${OPSYS:L}${OSREL}
.endif
REDUCECSL=	${WRKSRC}/cslbuild/${TARGET_SDIR}/csl

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${REDUCECSL}/reduce ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${REDUCECSL}/reduce.img ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${FILESDIR}/runcsl.sh ${STAGEDIR}${PREFIX}/bin/redcsl
	${INSTALL_MAN} ${FILESDIR}/redcsl.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DATADIR}/reduce.doc
	(cd ${REDUCECSL}/reduce.doc && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${DATADIR}/reduce.doc)
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTDIR}
	(cd ${REDUCECSL}/reduce.fonts && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${DATADIR}/reduce.fonts)

.include <bsd.port.post.mk>
