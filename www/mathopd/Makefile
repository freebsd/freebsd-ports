# New ports collection makefile for:    mathopd HTTPD
# Date created:         Sun Oct 31 1999
# Whom:                 tobez@plab.ku.dk
#
# $FreeBSD$
#

PORTNAME=	mathopd
PORTVERSION=	1.3p7
CATEGORIES=	www
MASTER_SITES=	http://www.mathopd.org/dist/ \
		ftp://ftp.prima.eu.org/pub/mirrored_files/mathop.diva.nl/ \
		http://www.tobez.org/download/port-mirrors/www/mathopd/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pl/}

MAINTAINER=	tobez@tobez.org

post-install:
	@${INSTALL_DATA} ${FILESDIR}/mathopd.conf.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mathopd
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/mathopd
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/mathopd
	@${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/mathopd
.endif
	@if [ ! -f ${PREFIX}/etc/rc.d/mathopd.sh ]; then \
		${INSTALL_SCRIPT} ${FILESDIR}/mathopd.sh ${PREFIX}/etc/rc.d/mathopd.sh; \
	fi
	@${SED} -e 's,/usr/local,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
