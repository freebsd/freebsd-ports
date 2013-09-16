# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	savelogs
PORTVERSION=	1.98
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SCOTTW

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Save log files in a nice way

USES=		perl5
USE_PERL5=	configure

MAN1=		rotation.1 savelogs.1

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/savelogs.conf.sample ${PREFIX}/etc/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/savelogs.conf.lint ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
