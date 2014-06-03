# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chemtool
PORTVERSION=	1.6.11
PORTREVISION=	4
CATEGORIES=	science
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Draw organic molecules easily and store them

RUN_DEPENDS=	transfig:${PORTSDIR}/print/transfig

USE_GNOME=	gtk20
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-emf=yes --with-localedir=${PREFIX}

.include <bsd.port.pre.mk>

#isolate libEMF stuff
LIB_DEPENDS+=	libEMF.so:${PORTSDIR}/graphics/libemf
CFLAGS+=	-I${LOCALBASE}/include/libEMF

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chemtool ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src-cht/cht ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/chemtool.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cht.1 ${STAGEDIR}${MANPREFIX}/man/man1
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
