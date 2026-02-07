PORTNAME=	watchmen
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	proler@gmail.com
COMMENT=	Watch and restart daemons
WWW=		https://github.com/proller/watchmen

LICENSE=	GPLv3+

RUN_DEPENDS=	p5-libwww>=6.04:www/p5-libwww \
		p5-URI>=0:net/p5-URI

USE_GITHUB=	yes
GH_ACCOUNT=	proller

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	watchmen
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME} \
		"@sample etc/${PORTNAME}.conf.sample" \
		${SITE_MAN1}/${PORTNAME}.1.gz

OPTIONS_DEFINE=	MYSQL PGSQL EMAIL
MYSQL_DESC=	Enable test mysql queries
PGSQL_DESC=	Enable test postgresql queries
EMAIL_DESC=	Report problems by email

MYSQL_RUN_DEPENDS=	${DBD_MYSQL}
PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=2.19.2:databases/p5-DBD-Pg
EMAIL_RUN_DEPENDS=	p5-MIME-Lite>=0:mail/p5-MIME-Lite

MYSQL_USES=	mysql

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.dist ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
