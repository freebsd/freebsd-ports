# ex:ts=8
# Ports collection makefile for:  lr
# Date created:                          Tue Jul 14, 2002
# Whom:                                  Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	lr
PORTVERSION=	2.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lazyread
DISTNAME=	lazyread-${PORTVERSION}

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Lazyread can auto-scroll files on your screen in movie credit fashion

.include <bsd.port.pre.mk>

.if exists(/usr/bin/lesspipe.sh)
LESSPIPE_PATH=/usr/bin/
PLIST_SUB+=	LESSPIPE="@comment "
.else
.if exists(${LOCALBASE}/bin/lesspipe.sh)
LESSPIPE_PATH=${LOCALBASE}/bin/
PLIST_SUB+=	LESSPIPE="@comment "
.else
INSTALL_LESSPIPE=1
LESSPIPE_PATH=${LOCALBASE}/bin/
PLIST_SUB+=	LESSPIPE=""
.endif
.endif

LDFLAGS+=	-lncurses
WRKSRC=		${WRKDIR}/${DISTNAME}

USE_REINPLACE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|getenv("LESSOPEN")|"\|${LESSPIPE_PATH}lesspipe.sh"|' ${WRKSRC}/lazyread.c

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} -o lr lazyread.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lr ${PREFIX}/bin

.if defined(INSTALL_LESSPIPE)
	${INSTALL_SCRIPT} ${FILESDIR}/lesspipe.sh ${PREFIX}/bin
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
