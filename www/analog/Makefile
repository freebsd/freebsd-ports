# Created by: jfitz
# $FreeBSD$

PORTNAME=	analog
PORTVERSION=	6.0
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.analog.cx/ \
		http://analog.gsp.com/ \
		http://fossies.org/unix/www/ \
		ftp://ftp.polytechnic.edu.na/pub/analog/ \
		http://analog.tzone.it/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast program for analysing WWW logfiles

LICENSE=	GPLv2

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

BUILD_WRKSRC=	${WRKSRC}/src

ALL_TARGET=	${PORTNAME}

SUB_FILES=	pkg-message

MAN1=		analog.1

LIMGDIR?=	www/data/images
IMGDIR=		${PREFIX}/${LIMGDIR}
PLIST_SUB=	IMGDIR="${LIMGDIR}"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/analog ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/analog.man ${MANPREFIX}/man/man1/analog.1
	${INSTALL_DATA} ${WRKSRC}/analog.cfg ${PREFIX}/etc/analog.cfg-dist
	@${MKDIR} ${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/lang/* ${DATADIR}/lang
	@${MKDIR} ${IMGDIR}
	${INSTALL_DATA} ${WRKSRC}/images/* ${IMGDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.cfg ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/anlgform.html ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/anlgform.pl ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/css
	${INSTALL_DATA} ${WRKSRC}/examples/css/Readme.txt ${EXAMPLESDIR}/css
	${INSTALL_DATA} ${WRKSRC}/examples/css/default.css ${EXAMPLESDIR}/css
	@${MKDIR} ${EXAMPLESDIR}/css/jreeves
	${INSTALL_DATA} ${WRKSRC}/examples/css/jreeves/* ${EXAMPLESDIR}/css/jreeves
.endif
.if !exists(${PREFIX}/etc/analog.cfg)
	@cd ${PREFIX}/etc && ${CP} -f analog.cfg-dist analog.cfg
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
