# Created by: Dmitry Shulgachik <legh@legh.ru>
# $FreeBSD$

PORTNAME=	jx
PORTVERSION=	1.23
CATEGORIES=	sysutils
MASTER_SITES=	http://legh.ru/wp-content/uploads/jx/

MAINTAINER=	legh@legh.ru
COMMENT=	Wrapper to jexec with more feature in interpreting jail id

BROKEN=		unfetchable

USES=		perl5
NO_BUILD=	yes
USE_PERL5=	run

PLIST_FILES=	bin/jx man/man1/jx.1.gz

OPTIONS_DEFINE=	CONFIG
CONFIG_DESC=	Enable custom config (recuire Config::General)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCONFIG}
RUN_DEPENDS=	p5-Config-General>=0:devel/p5-Config-General
PLIST_FILES+=	etc/${PORTNAME}.cfg.sample
.endif

post-patch:
.if ${PORT_OPTIONS:MCONFIG}
	${REINPLACE_CMD} -e 's/use constant use_config => 0;/use constant use_config => 1;/' ${WRKSRC}/${PORTNAME}.pl
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${STAGEDIR}${PREFIX}/man/man1
.if ${PORT_OPTIONS:MCONFIG}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.cfg.sample \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample
.endif

.include <bsd.port.mk>
