# New ports collection makefile for:   tdetect
# Date created:			  Sun Jan 31, 1997
# Whom:               		  shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	tdetect
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	http://sb.123.org/ \
		http://www.genocide2600.com/~tattooman/unix-loggers/ \
		http://ftp.ceti.com.pl/pub/scout/progs/Unix/

MAINTAINER=	shipley@dis.org

.include <bsd.port.pre.mk>

pre-configure:
	${PERL} -pi.dist -e 's/trdetect/tdetect/g' ${WRKSRC}/config.h
.if ${OSVERSION} > 330002
	${PERL} -pi.orig -e 's/LOG_AUTHPRIV/LOG_SECURITY/g' ${WRKSRC}/config.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tdetect ${PREFIX}/sbin/tdetect

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/tdetect.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/tdetect.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/tdetect.sh; \
		${ECHO} "ETHERNETDEV=ed0" >> ${PREFIX}/etc/rc.d/tdetect.sh; \
		${ECHO} '[ -x ${PREFIX}/sbin/tdetect ] && ${PREFIX}/sbin/tdetect $$ETHERNETDEV && ${ECHO} -n " tdetect"' >> ${PREFIX}/etc/rc.d/tdetect.sh; \
		${CHMOD} 750 ${PREFIX}/etc/rc.d/tdetect.sh; \
		${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}; \
	fi

.include <bsd.port.post.mk>
