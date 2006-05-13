# New ports collection makefile for: xca
# Date created:		2002-12-23
# Whom:			Valentin Zahariev <curly@e-card.bg>
#
# $FreeBSD$
#

PORTNAME=	xca
PORTVERSION=	0.5.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	curly@e-card.bg
COMMENT=	Graphical certification authority

LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4

USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_QT_VER=	3

.include <bsd.port.pre.mk>

post-patch:
	@echo "CPPFLAGS= -I. -I.. -I${OPENSSLINC} ${QTCPPFLAGS} -I${LOCALBASE}/include/db4" > ${WRKSRC}/Local.mak
	@echo "CFLAGS= ${CFLAGS}" >> ${WRKSRC}/Local.mak
	@echo "LDFLAGS= ${LDFLAGS}" >> ${WRKSRC}/Local.mak
	@echo "LIBS= ${QTCFGLIBS} -lqt-mt -L${OPENSSLLIB} -lcrypto -ldb4_cxx ${PTHREAD_LIBS}" >> ${WRKSRC}/Local.mak
	@echo "MOC=${MOC}" >> ${WRKSRC}/Local.mak
	@echo "UIC=${QT_PREFIX}/bin/uic" >> ${WRKSRC}/Local.mak
	@echo "CC=${CXX}" >> ${WRKSRC}/Local.mak
	@echo "LD=${LD}" >> ${WRKSRC}/Local.mak
	@echo "STRIP=${STRIP_CMD}" >> ${WRKSRC}/Local.mak
	@echo "prefix=${PREFIX}" >> ${WRKSRC}/Local.mak
	@echo "etc=${PREFIX}/etc/xca" >> ${WRKSRC}/Local.mak
	@echo "basedir=" >> ${WRKSRC}/Local.mak
	@${REINPLACE_CMD} -E -e 's|QFont\ font\(\ font\(\)\ \)|QFont font|' ${WRKSRC}/widgets/clicklabel.cpp
	@${REINPLACE_CMD} -E -e 's|(install[\ \:]+xca\.1)\.gz|\1|g' ${WRKSRC}/doc/Makefile

MAN1=	xca.1

.include <bsd.port.post.mk>
