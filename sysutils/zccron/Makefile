# New ports collection makefile for: zccron
# Date created:        24 June 2008
# Whom:                Zane C. Bowers
#
# $FreeBSD$
#

PORTNAME=	zccron
PORTVERSION=	0.0.0
CATEGORIES=	sysutils deskutils
MASTER_SITES=	http://cpan.org/authors/id/V/VV/VVELOX/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A cron like tool that performs a single pass on a crontab stored in ZConf

RUN_DEPENDS=	${SITE_PERL}/DateTime/Event/Cron.pm:${PORTSDIR}/devel/p5-DateTime-Event-Cron \
		${SITE_PERL}/${PERL_ARCH}/DateTime/Duration.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Format/Strptime.pm:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		${SITE_PERL}/ZConf.pm:${PORTSDIR}/net/p5-ZConf

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
MAN1=		${PORTNAME}.1

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CP} -v ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-build:
	@${EXEC} pod2man --section=1 --release=${PORTVERSION} --name=${PORTNAME} --center=${PORTNAME}" user guide" ${WRKSRC}/${DISTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	@${CP} -v ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}
	@${CP} -v ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/${PORTNAME}.1
	@${CHMOD} +x ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
