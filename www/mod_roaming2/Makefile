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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Apache module that works as a Netscape Roaming Access server

USE_APACHE=	yes
WITH_APACHE2=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/2$//}
PORTDOCS=	CHANGES	INSTALL	LICENSE	README
PLIST_FILES=	etc/apache2/httpd.conf.mod_roaming \
		libexec/apache2/mod_roaming.so

do-build:
	@cd ${WRKSRC} && \
	${APXS} -c mod_roaming.c

do-install:
	${APXS} -i -n roaming ${WRKSRC}/mod_roaming.la
	${INSTALL_DATA} ${FILESDIR}/httpd.conf.${PORTNAME:S/2$//} ${PREFIX}/etc/apache2/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
