# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	gstfs
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://bobcopeland.com/gstfs/releases/ \
		http://mirror.mcx2.org/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	On-demand, transcoding filesystem (using GStreamer pipeline)

USES=		fuse pkgconfig
USE_GSTREAMER=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README
PORTEXAMPLES=	ogg2mp3.sh mp32wav.sh

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
