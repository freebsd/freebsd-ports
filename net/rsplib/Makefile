# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>
# $FreeBSD$

PORTNAME=	rsplib
PORTVERSION=	3.0.1
CATEGORIES=	net
MASTER_SITES=	http://www.tdr.wiwi.uni-due.de/fileadmin/fileupload/I-TDR/ReliableServer/Downloads/ \
		http://www.exp-math.uni-essen.de/~dreibh/rserpool/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	RSerPool Framework and Example Applications

LICENSE=	GPLv3

USE_QT4=	gui xml moc_build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-mode \
		--enable-qt --with-qt-lib=${QT_LIBDIR} \
		--with-qt-include=${QT_INCDIR}
USE_LDCONFIG=	yes

MAN1=		calcappclient.1 \
		cspmonitor.1 \
		fractalpooluser.1 \
		hsdump.1 \
		pingpongclient.1 \
		registrar.1 \
		rspregistrar.1 \
		rspserver.1 \
		rspterminal.1 \
		scriptingclient.1 \
		scriptingcontrol.1 \
		scriptingserviceexample.1 \
		server.1 \
		terminal.1


.include <bsd.port.mk>
