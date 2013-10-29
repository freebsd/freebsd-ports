# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	mochiweb
PKGNAMEPREFIX=	erl-
PORTVERSION=	2.7.0
#PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	GH

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Erlang library for building lightweight HTTP servers

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar \
	erl:${PORTSDIR}/lang/erlang

RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

USE_GITHUB=	yes
GH_ACCOUNT=	mochi
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	8c2e78e

#USE_GMAKE=	yes
#ALL_TARGET=		build_plt
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

do-build:
	(cd ${WRKSRC} && rebar compile)

do-install:
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/scripts
	${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/ebin/*.app  ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/*.erl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/include/*.hrl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/scripts/*.erl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/scripts

.include <bsd.port.mk>
