# New ports collection makefile for:	savelogs
# Date created:		2004-04-29
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	savelogs
PORTVERSION=	1.81
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/S/SC/SCOTTW/

MAINTAINER=	ports@c0decafe.net
COMMENT=	Save log files in a nice way

PERL_CONFIGURE=	YES
MAN1=		rotation.1 savelogs.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/FAQ ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/conf/savelogs.conf.lint ${EXAMPLESDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/conf/savelogs.conf.sample ${PREFIX}/etc/

.include <bsd.port.mk>
