# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	pv
PORTVERSION=	1.4.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ivarch.com/programs/sources/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A pipe throughput monitor

LICENSE=	ART20

CONFLICTS=	waon-[0-9]*

PROJECTHOST=	pipeviewer
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		pv.1
PLIST_FILES=	bin/pv
PORTDOCS=	README INSTALL NEWS PACKAGE \
		TODO VERSION release-checklist

OPTIONS_DEFINE=	NLS LFS
OPTIONS_DEFAULT=	LFS

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLFS}
CONFIGURE_ARGS+=	--enable-lfs
.else
CONFIGURE_ARGS+=	--disable-lfs
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-static-nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

post-patch:
	@${CP} ${WRKSRC}/README ${WRKSRC}/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pv ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/quickref.1 ${MAN1PREFIX}/man/man1/pv.1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
