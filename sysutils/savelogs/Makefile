# New ports collection makefile for:	savelogs
# Date created:		2004-04-29
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	savelogs
PORTVERSION=	1.97
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SCOTTW

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Save log files in a nice way

PERL_CONFIGURE=	yes

MAN1=		rotation.1 savelogs.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/conf/savelogs.conf.sample ${PREFIX}/etc/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/FAQ ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/conf/savelogs.conf.lint ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
