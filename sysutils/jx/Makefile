# New ports collection makefile for:   jx
# Date created:        15 December 2008
# Whom:                Dmitry Shulgachik <legh@legh.ru>
#
# $FreeBSD$
#

PORTNAME=	jx
PORTVERSION=	1.23
CATEGORIES=	sysutils
MASTER_SITES=	http://legh.ru/wp-content/uploads/jx/

MAINTAINER=	legh@legh.ru
COMMENT=	Wrapper to jexec with more feature in interpreting jail id

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/${PORTNAME}

MAN1=		jx.1
MANCOMPRESSED=	yes

OPTIONS=	CONFIG  "Enable custom config (recuire Config::General)" Off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CONFIG)
RUN_DEPENDS=	${SITE_PERL}/Config/General.pm:${PORTSDIR}/devel/p5-Config-General
PLIST_FILES+=	etc/${PORTNAME}.cfg.sample
.endif

post-patch:
.if !defined(WITHOUT_CONFIG)
	${REINPLACE_CMD} -e 's/use constant use_config => 0;/use constant use_config => 1;/' ${WRKSRC}/${PORTNAME}.pl
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${PREFIX}/man/man1/${PORTNAME}.1.gz
.if !defined(WITHOUT_CONFIG)
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.cfg.sample ${PREFIX}/etc/${PORTNAME}.cfg.sample
.endif

.include <bsd.port.post.mk>
