# New ports collection makefile for: mb2md
# Date created:		20 June 2003
# Whom:			Andy Gilligan
#
# $FreeBSD$
#

PORTNAME=	mb2md
PORTVERSION=	3.20
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://batleth.sapienti-sat.org/projects/mb2md/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts mbox mailboxes to Maildir

RUN_DEPENDS=	${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate

EXTRACT_CMD=	${GZIP_CMD} -cd
EXTRACT_AFTER_ARGS=	> ${WRKDIR}/${PORTNAME}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_PERL5=	yes

PLIST_FILES=	bin/mb2md

post-patch:
	@${PERL} -pi -e 's|/usr/bin/perl|${PERL}|g' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
