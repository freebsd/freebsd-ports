# New ports collection makefile for:	linux-dislin
# Date created:				2003-12-14
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	dislin
PORTVERSION=	9.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.gwdg.de/pub/grafik/dislin/unix/
DISTNAME=	${PORTNAME}-${PORTVERSION}.fbsd${BINVER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scientific data plotting package

RESTRICTED=	"free for non-commercial use."
ONLY_FOR_ARCHS=	i386
USE_XLIB=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MD5_FILE=	${MASTERDIR}/distinfo${BINVER}
PLIST_SUB+=	VER=${PORTVERSION}
SUB_FILES=	dislin.sh pkg-message
SUB_LIST+=	DISLIN_DIR=${DISLIN_DIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
DISLIN_DIR=	${PREFIX}/dislin
PROGRAMS=	clink disaps disdrv disdrv_nw disdrv_w disgcl disgif dishlp	\
		disimg disman dismov distif dlink f2clink gclhelp gclhlp gclman

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000 && ${OSVERSION} < 600000
BINVER=		-5.4
.endif

.if ${OSVERSION} >= 600000
BINVER=		-6.0
.endif

do-install:
	(cd ${WRKSRC} && ${ENV} DISLIN=${DISLIN_DIR} ${SH} INSTALL)
	${INSTALL_SCRIPT} ${WRKDIR}/dislin.sh ${DISLIN_DIR}/bin
.for _program in ${PROGRAMS}
	${LN} -s ${DISLIN_DIR}/bin/dislin.sh ${PREFIX}/bin/${_program}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
