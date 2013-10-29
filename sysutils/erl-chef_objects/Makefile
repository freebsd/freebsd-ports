# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	chef_objects
PKGNAMEPREFIX=	erl-
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	GH

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Library defines the internal objects used by chef

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar \
	erl-ej>=0:${PORTSDIR}/devel/erl-ej \
	erl-jiffy>=0:${PORTSDIR}/devel/erl-jiffy \
	meck>=0:${PORTSDIR}/devel/meck \
	erl-ibrowse>=0:${PORTSDIR}/net/erl-ibrowse \
	erl-mini_s3>=0:${PORTSDIR}/net/erl-mini_s3 \
	erl-chef_authn>=0:${PORTSDIR}/sysutils/erl-chef_authn \
	erl-erlware_commons>=0:${PORTSDIR}/devel/erl-erlware_commons \
	erl-opscoderl_folsom>=0:${PORTSDIR}/devel/erl-opscoderl_folsom \
	pooler>=0:${PORTSDIR}/devel/pooler \
	erl-mixer>=0:${PORTSDIR}/devel/erl-mixer \
	erl-envy>=0:${PORTSDIR}/devel/erl-envy

RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
	erl-ej>=0:${PORTSDIR}/devel/erl-ej \
	erl-jiffy>=0:${PORTSDIR}/devel/erl-jiffy \
	meck>=0:${PORTSDIR}/devel/meck \
	erl-ibrowse>=0:${PORTSDIR}/net/erl-ibrowse \
	erl-mini_s3>=0:${PORTSDIR}/net/erl-mini_s3 \
	erl-chef_authn>=0:${PORTSDIR}/sysutils/erl-chef_authn \
	erl-erlware_commons>=0:${PORTSDIR}/devel/erl-erlware_commons \
	erl-opscoderl_folsom>=0:${PORTSDIR}/devel/erl-opscoderl_folsom \
	pooler>=0:${PORTSDIR}/devel/pooler \
	erl-mixer>=0:${PORTSDIR}/devel/erl-mixer \
	erl-envy>=0:${PORTSDIR}/devel/erl-envy


USE_GITHUB=	yes
GH_ACCOUNT=	opscode
GH_PROJECT=	chef_objects
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	5b8f81e

USE_GMAKE=	yes
ALL_TARGET=		compile
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

do-install:
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/priv
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/priv/depselector_rb
	${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/ebin/*.app  ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/*.erl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/include/*.hrl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/priv/depselector_rb/*   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/priv/depselector_rb

.include <bsd.port.mk>
