# New ports collection makefile for:	t-prot
# Date created:		2004-10-03
# Whom:			Sergei Kolobov <sergei@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	t-prot
PORTVERSION=	1.47
CATEGORIES=	mail
MASTER_SITES=	http://www.escape.de/users/tolot/mutt/t-prot/downloads/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	TOFU Protection - Display Filter for RFC822 messages

RUN_DEPENDS=	${SITE_PERL}/Getopt/Mixed.pm:${PORTSDIR}/devel/p5-Getopt-Mixed

USE_GPG=	yes
USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		t-prot.1
DOCS=		BUGS ChangeLog README TODO

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/t-prot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/t-prot.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
