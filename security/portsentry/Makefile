# New ports collection makefile for:	sentry
# Version required:	0.90
# Date created:		3 January 1998
# Whom:			chris@still.whet.org
#
# $FreeBSD$
#

DISTNAME=	portsentry-0.90
CATEGORIES=	security
MASTER_SITES=	http://www.psionic.com/tools/

MAINTAINER=	chris@still.whet.org

ALL_TARGET=	freebsd

post-patch:
	@/usr/bin/perl -pi -e 's,__PREFIX__,${PREFIX},g' ${WRKSRC}/portsentry.conf
	@/usr/bin/perl -pi -e 's,__PREFIX__,${PREFIX},g' ${WRKSRC}/portsentry_config.h

do-install:
.if !exists($(PREFIX)/etc/portsentry.conf)
	${INSTALL_DATA} ${WRKSRC}/portsentry.conf ${PREFIX}/etc
.endif
	${INSTALL_DATA} ${WRKSRC}/portsentry.conf ${PREFIX}/etc/portsentry.conf.default
	${INSTALL_DATA} ${WRKSRC}/portsentry.ignore ${PREFIX}/etc
	${INSTALL_PROGRAM} ${WRKSRC}/portsentry ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/portsentry
	${INSTALL_DATA} ${WRKSRC}/README.install ${WRKSRC}/README.methods \
	  ${PREFIX}/share/doc/portsentry
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
