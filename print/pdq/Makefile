# New ports collection makefile for:	pdq
# Version required:	2.1.1
# Date created:		15 May 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $Id$
#

DISTNAME=	pdq-2.1.1
CATEGORIES=	print
MASTER_SITES=	ftp://feynman.tam.uiuc.edu/pub/pdq/
EXTRACT_SUFX=	.tgz

MAINTAINER=	yinjieh@csie.nctu.edu.tw

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib12-config"

MAN1=		lpd_cancel.1 lpd_print.1 lpd_status.1 pdq.1 xpdq.1
MAN5=		printrc.5

post-install:
	${CP} ${WRKSRC}/sample_etc_printrc ${PREFIX}/etc/printrc.sample
	strip ${PREFIX}/bin/pdq
	strip ${PREFIX}/bin/xpdq
	strip ${PREFIX}/bin/lpd_cancel
	strip ${PREFIX}/bin/lpd_print
	strip ${PREFIX}/bin/lpd_status
	@${ECHO} '*******************************************************'
	@${ECHO} '*                                                     *'
	@${ECHO} '*     Please copy /usr/local/etc/printrc.sample to    *'
	@${ECHO} '*     /usr/local/etc/printrc by yourself, thanks.     *'
	@${ECHO} '*                                                     *'
	@${ECHO} '*******************************************************'

.include <bsd.port.mk>
