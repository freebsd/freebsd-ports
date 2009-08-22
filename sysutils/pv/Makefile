# New ports collection makefile for:	pv
# Date created:		04 May 2004
# Whom:			Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	pv
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/pipeviewer/pipeviewer/${PORTVERSION}

MAINTAINER=	daniel@roe.ch
COMMENT=	A pipe throughput monitor

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		pv.1
PLIST_FILES=	bin/pv
PORTDOCS=	README COPYING INSTALL NEWS PACKAGE \
		TODO VERSION release-checklist
OPTIONS=	LFS "Use large filesystem support" on \
		NLS "Use Native Language Support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_LFS)
CONFIGURE_ARGS+=	--disable-lfs
.endif
.if defined(WITH_NLS)
CONFIGURE_ARGS+=	--enable-static-nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

post-patch:
	@${CP} ${WRKSRC}/README ${WRKSRC}/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pv ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/quickref.1 ${MAN1PREFIX}/man/man1/pv.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif

test:
	cd ${WRKSRC} && make test

.include <bsd.port.post.mk>
