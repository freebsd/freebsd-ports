PORTNAME=	pic2fig
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	XCONTRIB/utilities

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Pic format to fig format converter

USES=		tar:Z

CFLAGS+=	-Wno-return-type

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/pic2fig share/man/man1/pic2fig.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pic2fig ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pic2fig.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.post.mk>
