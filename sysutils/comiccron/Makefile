# New ports collection makefile for: comiccron
# Date created:        12 February 2007
# Whom:                Zane C. Bowers
#
# $FreeBSD$
#

PORTNAME=	comiccron
PORTVERSION=	1.0.0
CATEGORIES=	sysutils deskutils
DISTNAME=	comiccron-${PORTVERSION}.pl
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A cron like tool that performs a single pass on a cronfile

RUN_DEPENDS=	${SITE_PERL}/DateTime/Event/Cron.pm:${PORTSDIR}/devel/p5-DateTime-Event-Cron \
		${SITE_PERL}/${PERL_ARCH}/DateTime/Duration.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Format/Strptime.pm:${PORTSDIR}/devel/p5-DateTime-Format-Strptime

USE_PERL5=	yes

NO_WRKSUBDIR=	yes

MASTER_SITES=	http://cpan.org/authors/id/V/VV/VVELOX/

MAN1=		comiccron.1

PLIST_FILES=	bin/comiccron

post-extract:
	@${CP} -v ${DISTDIR}/${DISTNAME} ${WRKSRC}

#nothing to configure
do-configure:
	@${ECHO} -n

do-build:
	@${EXEC} pod2man --section=1 --release=${PORTVERSION} --name=comiccron --center="comiccron user guide" ${WRKSRC}/${DISTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	@${CP} -v ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/comiccron
	@${CP} -v ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/${PORTNAME}.1
	@${CHMOD} +x ${PREFIX}/bin/comiccron

.include <bsd.port.mk>
