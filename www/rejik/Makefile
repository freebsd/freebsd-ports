PORTNAME=	rejik
PORTVERSION=	3.2.12
CATEGORIES=	www
MASTER_SITES=	http://www.rejik.ru/download/
DISTNAME=	redirector-${PORTVERSION}_squid_3.4

MAINTAINER=	roma.a.g@gmail.com
COMMENT=	Squid redirector used for blocking unwanted content

LICENSE=	BSD4CLAUSE

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:www/squid
LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		perl5 tar:tgz
MAKE_ARGS=	CC=${CC} INSTALL_PATH=${PREFIX}/rejik3

USERS=		squid
GROUPS=		squid

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
