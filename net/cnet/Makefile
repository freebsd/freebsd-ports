# Created by: jkh
# $FreeBSD$

PORTNAME=	cnet
PORTVERSION=	2.0.10
PORTREVISION=	2
CATEGORIES=	net tcl tk
MASTER_SITES=	http://www.csse.uwa.edu.au/cnet/ \
		ftp://ftp.giga.net.tw/OS/FreeBSD/distfiles/ \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	A networking simulator

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

USE_XORG=	xpm
USES=		gmake
ALL_TARGET=	# empty
MAN1=		cnet.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN=		Does not compile on amd64 or ia64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|8.3|8.4|g ; \
		 s|83|84|g' ${WRKSRC}/src/Makefile.freebsd
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cnet ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/cnet.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/DOC/cnet.man ${PREFIX}/man/man1/cnet.1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cnetlib/* ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/cnet
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES/* ${PREFIX}/share/examples/cnet
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/DOC/*.html ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/DOC/images/* ${DOCSDIR}/images
.endif

.include <bsd.port.post.mk>
