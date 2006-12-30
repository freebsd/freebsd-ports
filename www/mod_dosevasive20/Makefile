# New ports collection makefile for:	mod_evasive20
# Date created:				26 Jul 2004
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	mod_evasive20
PORTVERSION=	1.10.1
CATEGORIES=	www security
MASTER_SITES=	http://www.zdziarski.com/projects/mod_evasive/ \
		ftp://ftp.oav.net/pkg_freebsd/distfiles/
DISTNAME=	mod_evasive_${PORTVERSION}
DIST_SUBDIR=	apache2

MAINTAINER=	kiwi@oav.net
COMMENT=	An Apache 2 module to try to protect HTTP DoS or DDoS attacks

WRKSRC=		${WRKDIR}/${PORTNAME}

WANT_APACHE=	2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
WRKSRC=		${WRKDIR}/mod_evasive

PORTDOCS=	LICENSE README test.pl

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache20/Makefile.modules.3rd"

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
