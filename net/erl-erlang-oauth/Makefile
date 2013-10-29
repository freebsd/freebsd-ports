# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	erlang-oauth
PKGNAMEPREFIX=	erl-
PORTVERSION=	1.4.0
#PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	GH

BUILD_DEPENDS=	erl:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Erlang OAuth 1.0 implementation

USE_GITHUB=	yes
GH_ACCOUNT=	tim
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	3ad509d

USE_GMAKE=	yes
ALL_TARGET=		compile
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

do-install:
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/ebin/*.app  ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/*.erl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src

.include <bsd.port.mk>
