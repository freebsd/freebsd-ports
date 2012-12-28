# New ports collection makefile for:	watchmen
# Date created:		2009-07-16
# Whom:			Oleg Alexeenkov <proler@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	watchmen
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	proler@gmail.com
COMMENT=	Watch and restart daemons

LICENSE=	GPLv3

RUN_DEPENDS+=	p5-libwww>=6.04:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

OPTIONS_DEFINE=	MYSQL PGSQL EMAIL
MYSQL_DESC=	Want test mysql queries
PGSQL_DESC=	Want test postgresql queries
EMAIL_DESC=	report problems by email

USE_PERL5_RUN=	yes
POD2MAN?=	pod2man

MAN1=		${PORTNAME}.1
PLIST_FILES=	\
	bin/${PORTNAME}  \
	etc/${PORTNAME}.conf.dist  \
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/App/watchmen/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/App/watchmen \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/App

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
RUN_DEPENDS+=	p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
RUN_DEPENDS+=	p5-DBD-Pg>=2.19.2:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MEMAIL}
RUN_DEPENDS+=	p5-Email-Send>=2.198:${PORTSDIR}/mail/p5-Email-Send
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.dist ${PREFIX}/etc

.include <bsd.port.post.mk>
