# New ports collection makefile for:	pdq
# Date created:		15 May 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pdq
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://pdq.sourceforge.net/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A straightforward, flexible print subsystem

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pdqlibdir=${PREFIX}/etc/pdq

MAN1=		lpd_cancel.1 lpd_print.1 lpd_status.1 pdq.1 xpdq.1
MAN5=		printrc.5

post-install:
.for file in lpd_cancel lpd_print lpd_status pdq xpdq
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
