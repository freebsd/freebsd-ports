# Ports collection makefile for:	mod_chroot
# Date created:				May 18, 2004
# Whom:					Alexey A.Ukhov <auk@startext.de>
#
# $FreeBSD$
#

PORTNAME=	mod_chroot
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	http://core.segfault.pl/~hobbit/mod_chroot/dist/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	The mod_chroot makes running Apache in a chroot easy

PORTDOCS=	INSTALL CAVEATS README.Apache20 README
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.include <bsd.port.post.mk>
