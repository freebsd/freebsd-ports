# New ports collection makefile for: 	thttpd
# Date created:		24 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	thttpd
PORTVERSION=	2.20b
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.acme.com/software/thttpd/ \
		http://www.freenix.no/~anders/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} notes.html

MAINTAINER=	anders@fix.no

IGNOREFILES=	notes.html

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
GNU_CONFIGURE=	yes

MAN1=		makeweb.1 htpasswd.1
MAN8=		thttpd.8 redirect.8 ssi.8 syslogtocern.8

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/thttpd ${PREFIX}/sbin/
	@${INSTALL_MAN} ${WRKSRC}/thttpd.8 ${PREFIX}/man/man8
	@${INSTALL} -d -o root -g wheel -m 0775 ${PREFIX}/www
	@${INSTALL} -d -o root -g wheel -m 0775 ${PREFIX}/www/data
	@${INSTALL} -d -o root -g wheel -m 0775 ${PREFIX}/www/logs
	@${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/www/cgi-bin
	@${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/redirect ${PREFIX}/www/cgi-bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/ssi ${PREFIX}/www/cgi-bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/cgi-src/phf ${PREFIX}/www/cgi-bin/
	@${INSTALL_MAN} ${WRKSRC}/cgi-src/redirect.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/cgi-src/ssi.8 ${PREFIX}/man/man8
	@${INSTALL_PROGRAM} ${WRKSRC}/extras/makeweb ${PREFIX}/bin/
	@${INSTALL} -c -m 755 -o root -g wheel ${WRKSRC}/extras/syslogtocern ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/extras/htpasswd ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/extras/makeweb.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/extras/htpasswd.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/extras/syslogtocern.8 ${PREFIX}/man/man8
	@if [ ! -f ${PREFIX}/sbin/thttpd_wrapper ]; then \
		${ECHO} "Installing ${PREFIX}/sbin/thttpd_wrapper file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/sbin/thttpd_wrapper; \
		${ECHO} "${ECHO} \$$\$$ > /var/run/thttpd_wrapper.pid" >> ${PREFIX}/sbin/thttpd_wrapper; \
		${ECHO} "while true ; do" >> ${PREFIX}/sbin/thttpd_wrapper; \
		${ECHO} "	${PREFIX}/sbin/thttpd -D -C ${PREFIX}/etc/thttpd.conf" >> ${PREFIX}/sbin/thttpd_wrapper; \
		${ECHO} "	sleep 10" >> ${PREFIX}/sbin/thttpd_wrapper; \
		${ECHO} "done" >> ${PREFIX}/sbin/thttpd_wrapper; \
		${CHMOD} 751 ${PREFIX}/sbin/thttpd_wrapper; \
	fi
	@${ECHO} "Installing ${PREFIX}/etc/thttpd.conf.sample configuration file."
	@${ECHO} "dir=${PREFIX}/www/data" > ${PREFIX}/etc/thttpd.conf.sample
	@${ECHO} "chroot" >> ${PREFIX}/etc/thttpd.conf.sample
	@${ECHO} "cgipat=*.cgi" >> ${PREFIX}/etc/thttpd.conf.sample
	@${ECHO} "logfile=${PREFIX}/www/logs/thttpd.log" >> ${PREFIX}/etc/thttpd.conf.sample
	@${ECHO} "pidfile=/var/run/thttpd.pid" >> ${PREFIX}/etc/thttpd.conf.sample
	@if [ ! -f ${PREFIX}/etc/rc.d/thttpd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/thttpd.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/thttpd.sh ${PREFIX}/etc/rc.d/thttpd.sh; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/thttpd
	@${INSTALL_MAN} ${DISTDIR}/notes.html ${PREFIX}/share/doc/thttpd
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

post-configure: config-message

post-build: config-message

config-message:
	@${ECHO} "====================================================================="
	@${ECHO} ""
	@${ECHO} "Be sure to take a look at the options in config.h before (re)building"
	@${ECHO} "if you want to tweak the server."
	@${ECHO} ""
	@${ECHO} "====================================================================="

.include <bsd.port.mk>
