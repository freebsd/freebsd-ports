# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	gstfs
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://bobcopeland.com/gstfs/releases/ \
		http://mirror.mcx2.org/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	On-demand, transcoding filesystem (using GStreamer pipeline)

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		fuse pkgconfig
USE_GSTREAMER=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README
PORTEXAMPLES=	ogg2mp3.sh mp32wav.sh

post-patch:
	@${REINPLACE_CMD} 's/gcc/$$(CC)/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
