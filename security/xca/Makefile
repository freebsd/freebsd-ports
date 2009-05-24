# New ports collection makefile for: xca
# Date created:		2002-12-23
# Whom:			Valentin Zahariev <curly@e-card.bg>
#
# $FreeBSD$
#

PORTNAME=	xca
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	mark@foster.cc
COMMENT=	Graphical certification authority

USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build uic_build qmake_build rcc_build linguist_build
CC?=		gcc
CXX?=		g++

MAN1=		xca.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

post-patch:
	@echo "CPPFLAGS=-I. -I.. -I${WRKSRC}/ui -I${QT_INCDIR} -I${QT_INCDIR}/Qt -I${LOCALBASE}/include" > ${WRKSRC}/Local.mak
	@echo "CFLAGS= ${CFLAGS} -Wall -ggdb" >> ${WRKSRC}/Local.mak
	@echo "LDFLAGS= ${LDFLAGS} -L${QT_LIBDIR} -L${LOCALBASE}/lib" >> ${WRKSRC}/Local.mak
	@echo "LIBS= -lQtGui ${PTHREAD_LIBS} -lcrypto" >> ${WRKSRC}/Local.mak
	@echo "MOC=${MOC}" >> ${WRKSRC}/Local.mak
	@echo "UIC=${QT_PREFIX}/bin/uic-qt4" >> ${WRKSRC}/Local.mak
	@echo "RCC=${LOCALBASE}/bin/rcc"  >> ${WRKSRC}/Local.mak
	@echo "LRELEASE=${LOCALBASE}/bin/lrelease-qt4" >> ${WRKSRC}/Local.mak
	@echo "CC=${CC}" >> ${WRKSRC}/Local.mak
	@echo "LD=${LD}" >> ${WRKSRC}/Local.mak
	@echo "STRIP=${STRIP_CMD}" >> ${WRKSRC}/Local.mak
	@echo "prefix=${PREFIX}" >> ${WRKSRC}/Local.mak
	@echo "etc=${PREFIX}/etc/xca" >> ${WRKSRC}/Local.mak
	@echo "basedir=" >> ${WRKSRC}/Local.mak
	@echo "#define PREFIX \"${PREFIX}\"" > ${WRKSRC}/local.h
	@echo "#define ETC \"${PREFIX}/etc/xca\"" >> ${WRKSRC}/local.h
	@echo "#define VER \"${PORTVERSION}\"" >> ${WRKSRC}/local.h
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/lib/import.cpp

.include <bsd.port.post.mk>
