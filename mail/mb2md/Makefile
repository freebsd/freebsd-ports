# New ports collection makefile for: mb2md
# Date created:		20 June 2003
# Whom:			Andy Gilligan
#
# $FreeBSD$
#

PORTNAME=	mb2md
PORTVERSION=	3.10
CATEGORIES=	mail
MASTER_SITES=	http://batleth.sapienti-sat.org/projects/mb2md/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=	.gz

MAINTAINER=	andy@evo6.org
COMMENT=	Converts mbox mailboxes to Maildir

RUN_DEPENDS=	${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate

PLIST_FILES=	bin/mb2md
USE_PERL5_RUN=	yes
EXTRACT_CMD=	${GZIP_CMD} -cd > ${DISTNAME}
WRKSRC=		${.CURDIR}

NO_BUILD=	true
INSTALL_TARGET=	real-install

real-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
