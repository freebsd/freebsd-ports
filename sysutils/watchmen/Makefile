# New ports collection makefile for:	watchmen
# Date created:		2009-07-16
# Whom:			Oleg Alexeenkov <proler@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	watchmen
PORTVERSION=	0.05
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	proler@gmail.com
COMMENT=	Watch and restart daemons

OPTIONS=	MYSQL "Want test mysql queries" off \
		PGSQL "Want test postgresql queries" off \
		EMAIL "report problems by email" off

RUN_DEPENDS+=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

USE_PERL5_RUN=	yes
POD2MAN?=	pod2man

MAN1=		${PORTNAME}.1
PLIST_FILES=	\
	bin/${PORTNAME}  \
	etc/${PORTNAME}.conf.dist  \
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/watchmen/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/watchmen

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
RUN_DEPENDS+=	p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql${MYSQL_VER}
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if defined(WITH_EMAIL)
USE_PGSQL=	yes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Email/Send.pm:${PORTSDIR}/mail/p5-Email-Send
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.dist ${PREFIX}/etc

.include <bsd.port.post.mk>
