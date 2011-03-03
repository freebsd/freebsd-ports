# New ports collection makefile for:	rsplib
# Date created:		2010-08-08
# Whom:			Thomas Dreibholz <dreibh@iem.uni-due.de>
#
# $FreeBSD$
#

PORTNAME=	rsplib
PORTVERSION=	2.7.10
CATEGORIES=	net
MASTER_SITES=	http://www.tdr.wiwi.uni-due.de/fileadmin/fileupload/I-TDR/ReliableServer/Downloads/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	RSerPool Framework and Example Applications

USE_QT_VER=	4
QT_COMPONENTS=	gui xml moc_build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-mode \
		--enable-qt --with-qt-lib=${QT_LIBDIR} \
		--with-qt-include=${QT_INCDIR}
USE_LDCONFIG=	yes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

MAN8=		calcappclient.8 \
		cspmonitor.8 \
		fractalpooluser.8 \
		hsdump.8 \
		pingpongclient.8 \
		registrar.8 \
		scriptingclient.8 \
		scriptingcontrol.8 \
		scriptingserviceexample.8 \
		server.8 \
		terminal.8

MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700028
IGNORE=		requires sctp(4) support
.endif

.include <bsd.port.post.mk>
