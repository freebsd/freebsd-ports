# New ports collection makefile for:	neoupdate
# Date created:		9 January 2001
# Whom:			jim@thehousleys.net
#
# $FreeBSD$
#

PORTNAME=	neoupdate
PORTVERSION=	1.10
CATEGORIES=	net
MASTER_SITES=	http://www.iamnewbie.com/download/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	jeh@FreeBSD.org

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PERL=	yes
NO_BUILD=	yes

SITE_PERL=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}

.if !defined(NOPORTDOCS)
PLIST_SUB=	NOPORTDOCS=''
.else
PLIST_SUB=	NOPORTDOCS='@comment '
.endif

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/neoupdate.pl ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/ip.pl ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/neoupdate.conf ${PREFIX}/etc
	@${INSTALL_SCRIPT} ${WRKSRC}/yi.conf ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/neoupdate
	@${INSTALL_DATA} ${WRKSRC}/neoupdate.cron ${PREFIX}/share/doc/neoupdate
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/neoupdate
.endif
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.mk>
