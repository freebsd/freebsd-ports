# New ports collection makefile for:	gopod
# Date created:				4 April 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	gopod
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://gopod.free-go.net/gopod/ \
		CRITICAL
PKGNAMEPREFIX?=
DISTNAME=	goPod-${PORTVERSION}_linux_bsd

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT?=	Utility to cap/uncap an iPod

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAKE_ARGS+=	CC="${CC}"

RESTRICTED=	"Unclear legal status in EU countries"

.if ${PKGNAMEPREFIX} == ""
PLIST_FILES=	bin/gopod
WRKSRC=		${WRKDIR}/${DISTNAME}/console-version
.endif

PORTDOCS=	README_EN README_FR

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|h)" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

post-patch:
.if ${PKGNAMEPREFIX} == "gtk-"
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/gui.c
	@${REINPLACE_CMD} -E \
		's/^(CFLAGS|LDFLAGS).*=/\1+=/; s|(OS_FLAGS\))|\1 $${CFLAGS}|' \
		${WRKSRC}/Makefile
.else
	@${REINPLACE_CMD} -e 's|\($$(CC)\)|\1 $${CFLAGS}|; /strip/d' \
		${WRKSRC}/Makefile
.endif

do-install:
.if ${PKGNAMEPREFIX} == ""
	${INSTALL_PROGRAM} -m 0110 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.else
	@${MKDIR} ${DATADIR}
.for f in ${DATAFILES}
	${INSTALL_DATA} ${WRKSRC}/gfx/${f} ${DATADIR}
.endfor
	${INSTALL_PROGRAM} -m 0110 ${WRKSRC}/${PORTNAME} \
		${PREFIX}/bin/${UNIQUENAME}
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
