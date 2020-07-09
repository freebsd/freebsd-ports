# Created by: Elisey Savateev <b3k@mail.ru>
# $FreeBSD$

PORTNAME=	rejik
PORTVERSION=	3.2.11
PORTREVISION=	9
CATEGORIES=	www
MASTER_SITES=	http://www.rejik.ru/download/
DISTNAME=	redirector-${PORTVERSION}_squid_3.4

MAINTAINER=	roma.a.g@gmail.com
COMMENT=	Squid redirector used for blocking unwanted content

LICENSE=	BSD4CLAUSE

DEPRECATED=	Abandonware, requires MAKE_JOBS_UNSAFE, -fcommon,...
EXPIRATION_DATE=2020-10-05

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:www/squid
LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		perl5 tar:tgz
USE_GCC=	any
MAKE_ARGS=	CC=${CC} INSTALL_PATH=${PREFIX}/rejik3
CFLAGS+=	-fcommon

USERS=		squid
GROUPS=		squid

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
