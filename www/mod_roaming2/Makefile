# New ports collection makefile for:	mod_roaming2
# Date created:			15 May 2002
# Whom:				Vivek Khera <vivek@khera.org>
#
# based on mod_roaming port
#
# $FreeBSD$
#

PORTNAME=	mod_roaming2
PORTVERSION=	2.0.0
CATEGORIES=	www
MASTER_SITES=	http://www.klomp.org/mod_roaming/
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}

MAINTAINER=	vivek@kciLink.com

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache2

APXS=		${LOCALBASE}/sbin/apxs

DOCS=		CHANGES	INSTALL	LICENSE	README

do-build:
	@cd ${WRKSRC} && \
	${APXS} -c mod_roaming.c

do-install:
	${APXS} -i -n roaming ${WRKSRC}/mod_roaming.la
	${INSTALL_DATA} ${FILESDIR}/httpd.conf.${PORTNAME:S/2$//} ${PREFIX}/etc/apache2/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME:S/2$//}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME:S/2$//}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
