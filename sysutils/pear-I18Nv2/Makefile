# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	I18Nv2
PORTVERSION=	0.11.4
CATEGORIES=	sysutils devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Internationalization

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	iconv
PEAR_AUTOINSTALL=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/${PORTNAME}
	@${MV} ${WRKSRC}/[A-C]* ${WRKSRC}/${PORTNAME}
	@${MV} ${WRKSRC}/De* ${WRKSRC}/${PORTNAME}
	@${MV} ${WRKSRC}/[E-H]* ${WRKSRC}/${PORTNAME}
	@${MV} ${WRKSRC}/[L-S]* ${WRKSRC}/${PORTNAME}

.include <bsd.port.pre.mk>

PHP_VERS=	${PHP_VERSION:S/.//g}

.if defined(PHP_VERS) && ${PHP_VERS} < 406
#IGNORE=		You need PHP 4.0.6 or later to install PEAR::I18Nv2
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
