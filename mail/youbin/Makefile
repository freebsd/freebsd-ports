# New ports collection makefile for:	youbin
# Version required:		2.13
# Date created:			09 Aug 1996
# Whom:				Masafumi NAKANE <max@sfc.wide.ad.jp>
#
# $Id: Makefile,v 1.2 1996/08/21 09:25:28 asami Exp $
#

DISTNAME=	youbin-2.13
CATEGORIES+=	mail
MASTER_SITES=	ftp://nuis.nuie.nagoya-u.ac.jp/info/nagoya-u/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/net/

MAINTAINER=	max@sfc.wide.ad.jp

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
PREFIX=		${LOCALBASE}

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/youbind.sh

post-install:
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
		echo "Creating startup script '${STARTUP_SCRIPT}'" ;\
		echo "#!/bin/sh" > ${STARTUP_SCRIPT} ;\
		echo "if [ -f ${PREFIX}/sbin/youbind ]; then" >> \
			${STARTUP_SCRIPT} ;\
		echo "    ${PREFIX}/sbin/youbind &" >> ${STARTUP_SCRIPT} ;\
		echo "    echo -n ' youbind'" >> ${STARTUP_SCRIPT} ;\
		echo "fi" >> ${STARTUP_SCRIPT} ;\
		chmod 755 ${STARTUP_SCRIPT} ;\
	fi
	@-(grep -v ^# /etc/inetd.conf | grep comsat > /dev/null) && \
	 (echo "Now you need to edit /etc/inetd.conf and comment out the" ;\
	  echo "entry for comsat.  Then, do:" ;\
	  echo "kill -HUP `cat /var/run/inetd.pid`")

.include <bsd.port.mk>
