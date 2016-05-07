# Created by: Oleg Alexeenkov <proler@gmail.com>
# $FreeBSD$

PORTNAME=	watchmen
PORTVERSION=	0.08
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	proler@gmail.com
COMMENT=	Watch and restart daemons

LICENSE=	GPLv3

RUN_DEPENDS=	p5-libwww>=6.04:www/p5-libwww \
		p5-URI>=0:net/p5-URI

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	watchmen

OPTIONS_DEFINE=	MYSQL PGSQL EMAIL
MYSQL_DESC=	Want test mysql queries
PGSQL_DESC=	Want test postgresql queries
EMAIL_DESC=	report problems by email

POD2MAN?=	pod2man

PLIST_FILES=	bin/${PORTNAME} \
		"@sample etc/${PORTNAME}.conf.sample" \
		${SITE_MAN1}/${PORTNAME}.1.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
RUN_DEPENDS+=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
RUN_DEPENDS+=	p5-DBD-Pg>=2.19.2:databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MEMAIL}
RUN_DEPENDS+=	p5-MIME-Lite>=0:mail/p5-MIME-Lite
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.dist ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
