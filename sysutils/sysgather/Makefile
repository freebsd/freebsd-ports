PORTNAME=	sysgather
DISTVERSION=	1.0pre10
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/sysgather/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keep configuration files under version control
WWW=		https://devel.ringlet.net/sysutils/sysgather/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	p5-Config-IniFiles>=0:devel/p5-Config-IniFiles
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix uidfix
SHEBANG_FILES=	sysgather.pl
NO_ARCH=	yes

MAKE_ARGS=	MANDIR=${PREFIX}/share/man/man
OPTIONS_DEFINE=	EXAMPLES

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/sysgather.conf.default \
		${STAGEDIR}${PREFIX}/etc/sysgather.conf.sample

.include <bsd.port.mk>
