# New ports collection makefile for:	bruteforceblocker
# Date created:				20 April 2005
# Whom:					Daniel Gerzo <danger@rulez.sk>
#
# $FreeBSD$
#

PORTNAME=	bruteforceblocker
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://danger.rulez.sk/projects/bruteforceblocker/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	danger@rulez.sk
COMMENT=	Checks for failed login attempts and blocks given IPs

RUN_DEPENDS=	${SITE_PERL}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail

NO_BUILD=	yes
USE_PERL5_RUN=	yes
USE_RC_SUBR=	${PORTNAME}.sh

WRKSRC=		${WRKDIR}
PLIST_FILES=	bin/${PORTNAME}.pl
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Perl 5.6 or newer required. Install lang/perl5 or lang/perl5.8 and try again.
.endif

.if ${OSVERSION} < 502106
IGNORE=		requires at least FreeBSD 5.2
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}.pl
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
