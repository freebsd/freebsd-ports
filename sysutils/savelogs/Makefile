# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	savelogs
PORTVERSION=	1.98
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SCOTTW

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Save log files in a nice way

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/savelogs.conf.sample ${STAGEDIR}${PREFIX}/etc/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/savelogs.conf.lint ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
