# New ports collection makefile for:	mod_roaming2
# Date created:			15 May 2002
# Whom:				Vivek Khera <vivek@khera.org>
#
# based on mod_roaming port
#
# $FreeBSD$
#

PORTNAME=	mod_roaming2
PORTVERSION=	2.0b1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.klomp.org/mod_roaming/
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	An Apache module that works as a Netscape Roaming Access server

MAKE_JOBS_SAFE=  yes

USE_APACHE=	2.0+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
MODULENAME=	${PORTNAME:S/2$//}

PORTDOCS=	CHANGES	INSTALL	LICENSE	README
PLIST_FILES=	${APACHEETCDIR}/httpd.conf.mod_roaming

post-install:
	${INSTALL_DATA} ${FILESDIR}/httpd.conf.${PORTNAME:S/2$//} ${LOCALBASE}/${APACHEETCDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
