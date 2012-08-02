# New ports collection makefile for: qar-bufo
# Date created:        8 March 2007
# Whom:                Zane C. Bowers
#
# $FreeBSD$
#

PORTNAME=	qar-bufo
PORTVERSION=	1.3.1
CATEGORIES=	mail
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MWCZANECB
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Generates the Qmail assign and recipients file based on unix groups

USE_PERL5=	yes
NO_WRKSUBDIR=	yes

MAN1=		qar-bufo.1

PLIST_FILES=	bin/qar-bufo

post-extract:
	@${CP} -v ${DISTDIR}/${DISTNAME} ${WRKSRC}

#nothing to configure
do-configure:
	@${ECHO} -n

do-build:
	@${EXEC} pod2man --section=1 --release=${PORTVERSION} --name=${PORTNAME} --center="${PORTNAME} user guide" ${WRKSRC}/${DISTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	@${CP} -v ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}
	@${CP} -v ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1/${PORTNAME}.1
	@${CHMOD} +x ${PREFIX}/bin/qar-bufo

.include <bsd.port.mk>
