# New ports collection makefile for:    mathopd HTTPD
# Version required:     1.3pl4
# Date created:         Sun Oct 31 1999
# Whom:                 tobez@plab.ku.dk
#
# $FreeBSD$
#

DISTNAME=	mathopd-1.3pl4
CATEGORIES=	www
MASTER_SITES=	http://mathop.diva.nl/dist/ \
		ftp://ftp.prima.eu.org/pub/mirrored_files/mathop.diva.nl/

MAINTAINER=	tobez@plab.ku.dk

post-install:
	@${INSTALL_DATA} ${FILESDIR}/mathopd.conf.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mathopd
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/mathopd
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/mathopd
	@${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/mathopd
.endif
	@if [ ! -f ${PREFIX}/etc/rc.d/mathopd.sh ]; then \
		${ECHO} "#! ${SH}" > ${PREFIX}/etc/rc.d/mathopd.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/mathopd ] && ${PREFIX}/sbin/mathopd < ${PREFIX}/etc/mathopd.conf && ${ECHO} -n ' mathopd'" >> ${PREFIX}/etc/rc.d/mathopd.sh; \
		${CHMOD} 440 ${PREFIX}/etc/rc.d/mathopd.sh; \
	fi
	@${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
