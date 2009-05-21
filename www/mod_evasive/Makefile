# New ports collection makefile for:	mod_dosevasive20
# Date created:				26 Jul 2004
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	mod_evasive
PORTVERSION=	1.10.1
CATEGORIES=	www security
MASTER_SITES=	http://www.zdziarski.com/projects/mod_evasive/ \
		ftp://ftp.oav.net/pkg_freebsd/distfiles/
DISTNAME=	mod_evasive_${PORTVERSION}
DIST_SUBDIR=	apache2

MAINTAINER=	kiwi@oav.net
COMMENT=	An Apache module to try to protect the HTTP Server from DoS/DDoS attacks

MAKE_JOBS_SAFE=  yes

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_APACHE=	1.3+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

PORTDOCS=	LICENSE README test.pl

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} != "13"
MODULENAME=	${PORTNAME}20
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/bin/mail|/usr/bin/mail|g" \
		${WRKSRC}/mod_evasive.c ${WRKSRC}/mod_evasive20.c \
		${WRKSRC}/mod_evasiveNSAPI.c

post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.post.mk>
