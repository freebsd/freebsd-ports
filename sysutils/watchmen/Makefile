# New ports collection makefile for:	watchmen
# Date created:		2009-07-16
# Whom:			Oleg Alexeenkov <proler@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	watchmen
PORTVERSION=	0.02
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	proler@gmail.com
COMMENT=	Watch and restart daemons

RUN_DEPENDS+=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

USE_PERL5_RUN=	yes
POD2MAN?=	pod2man

MAN1=		${PORTNAME}.1
PLIST_FILES= \
	bin/${PORTNAME}  \
	etc/${PORTNAME}.conf.dist  \
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/watchmen/.packlist
PLIST_DIRS=%%SITE_PERL%%/%%PERL_ARCH%%/auto/watchmen

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
RUN_DEPENDS+=	p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.dist ${PREFIX}/etc

.include <bsd.port.post.mk>
