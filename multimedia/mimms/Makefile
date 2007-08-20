# New ports collection makefile for:	mimms
# Date created:		3 Jul 2007
# Whom:                	Yinghong.Liu <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	mimms
DISTVERSION=	2.0.1
CATEGORIES=	multimedia net
MASTER_SITES=	http://download.savannah.gnu.org/releases/mimms/ \
		http://ftp.cc.uoc.gr/mirrors/nongnu.org/mimms/ \
		http://dl.sv.gnu.org/releases/mimms/

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	Download streams using the MMS protocol

LIB_DEPENDS=	mms.0:${PORTSDIR}/net/libmms
RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake corelib moc uic

PLIST_FILES=	bin/mimms

MAN1=		mimms.1
PORTDOCS=	AUTHORS ChangeLog COPYING README

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/mimms.pro

do-configure:
	@cd ${WRKSRC} \
	&&  ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC}

do-install:
	@${INSTALL_MAN} ${WRKSRC}/mimms.1 ${PREFIX}/man/man1
	@${INSTALL_PROGRAM} ${WRKSRC}/mimms ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
