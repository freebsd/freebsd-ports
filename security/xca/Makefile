# Created by: Valentin Zahariev <curly@e-card.bg>
# $FreeBSD$

PORTNAME=	xca
PORTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical certification authority

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libltdl.so:${PORTSDIR}/devel/libltdl

USE_OPENSSL=	yes
USE_QT4=	gui moc_build uic_build qmake_build rcc_build linguist_build
USES=		desktop-file-utils gmake shared-mime-info
DESTDIRNAME=	destdir

.include <bsd.port.pre.mk>

BROKEN_sparc64=	fails to link

.if ${OSVERSION} >= 1000054
LD_CXX_LIB=	-lc++
.endif

post-patch:
	@echo "CPPFLAGS=-I. -I.. -I${WRKSRC}/ui -I${QT_INCDIR} -I${QT_INCDIR}/Qt -I${LOCALBASE}/include" > ${WRKSRC}/Local.mak
	@echo "CFLAGS= ${CFLAGS} -Wall -ggdb" >> ${WRKSRC}/Local.mak
	@echo "LDFLAGS= ${LDFLAGS}" >> ${WRKSRC}/Local.mak
	@echo "LIBS= ${LIBS} -L${QT_LIBDIR} -L${LOCALBASE}/lib -lQtCore -lQtGui -lpthread -lcrypto -lltdl ${LD_CXX_LIB}" >> ${WRKSRC}/Local.mak
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
	@echo "docdir=${DOCSDIR}" >> ${WRKSRC}/Local.mak
	@echo "#define PREFIX \"${PREFIX}\"" > ${WRKSRC}/local.h
	@echo "#define ETC \"${PREFIX}/etc/xca\"" >> ${WRKSRC}/local.h
	@echo "#define VER \"${PORTVERSION}\"" >> ${WRKSRC}/local.h
	@echo "#define DOCDIR \"${DOCSDIR}\"" >> ${WRKSRC}/local.h
	@${REINPLACE_CMD} -e "/rR/{G;s/$$/TOPDIR_/;}" -e "s:\(TOPDIR\)_:\1=${WRKSRC}:" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "/VPATH/{G;s/$$/TOPDIR_/;}" -e "s:\(TOPDIR\)_:\1=${WRKSRC}:" ${WRKSRC}/misc/Makefile
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/lib/import.cpp

.include <bsd.port.post.mk>
