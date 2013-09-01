# Created by: Oleg Alexeenkov <proler@gmail.com>
# $FreeBSD$

PORTNAME=	watchmen
PORTVERSION=	0.08
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	proler@gmail.com
COMMENT=	Watch and restart daemons

LICENSE=	GPLv3

RUN_DEPENDS=	p5-libwww>=6.04:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	watchmen

OPTIONS_DEFINE=	MYSQL PGSQL EMAIL
MYSQL_DESC=	Want test mysql queries
PGSQL_DESC=	Want test postgresql queries
EMAIL_DESC=	report problems by email

POD2MAN?=	pod2man

MAN1=		${PORTNAME}.1
PLIST_FILES=	\
	bin/${PORTNAME}  \
	etc/${PORTNAME}.conf.dist  \
	%%SITE_PERL%%/%%PERL_ARCH%%/auto/App/watchmen/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/App/watchmen \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/App

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
RUN_DEPENDS+=	p5-DBD-Pg>=2.19.2:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MEMAIL}
RUN_DEPENDS+=	p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.dist ${PREFIX}/etc

.include <bsd.port.post.mk>
