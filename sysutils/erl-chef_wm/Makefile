# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	chef_wm
PORTVERSION=	0.0.1
#PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GH
PKGNAMEPREFIX=	erl-

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Webmachine layer for the Chef server

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar \
	erl-opscoderl_wm>=0:${PORTSDIR}/www/erl-opscoderl_wm \
	erl-chef_authn>=0:${PORTSDIR}/sysutils/erl-chef_authn \
	erl-chef_certgen>=0:${PORTSDIR}/sysutils/erl-chef_certgen \
	erl-chef_db>=0:${PORTSDIR}/sysutils/erl-chef_db \
	erl-chef_index>=0:${PORTSDIR}/sysutils/erl-chef_index \
	erl-chef_objects>=0:${PORTSDIR}/sysutils/erl-chef_objects \
	erl-erlang-bcrypt>=0:${PORTSDIR}/security/erl-erlang-bcrypt \
	erl-fast-log-erlang>=0:${PORTSDIR}/sysutils/erl-fast-log-erlang \
	erl-mixer>=0:${PORTSDIR}/devel/erl-mixer \
	erl-stats_hero>=0:${PORTSDIR}/sysutils/erl-stats_hero \
	erl-folsom>=0:${PORTSDIR}/devel/erl-folsom \
	webmachine>=0:${PORTSDIR}/www/webmachine \
	erl-envy>=0:${PORTSDIR}/devel/erl-envy
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
	erl-opscoderl_wm>=0:${PORTSDIR}/www/erl-opscoderl_wm \
	erl-chef_authn>=0:${PORTSDIR}/sysutils/erl-chef_authn \
	erl-chef_certgen>=0:${PORTSDIR}/sysutils/erl-chef_certgen \
	erl-chef_db>=0:${PORTSDIR}/sysutils/erl-chef_db \
	erl-chef_index>=0:${PORTSDIR}/sysutils/erl-chef_index \
	erl-chef_objects>=0:${PORTSDIR}/sysutils/erl-chef_objects \
	erl-erlang-bcrypt>=0:${PORTSDIR}/security/erl-erlang-bcrypt \
	erl-fast-log-erlang>=0:${PORTSDIR}/sysutils/erl-fast-log-erlang \
	erl-mixer>=0:${PORTSDIR}/devel/erl-mixer \
	erl-stats_hero>=0:${PORTSDIR}/sysutils/erl-stats_hero \
	erl-folsom>=0:${PORTSDIR}/devel/erl-folsom \
	webmachine>=0:${PORTSDIR}/www/webmachine \
	erl-envy>=0:${PORTSDIR}/devel/erl-envy

USE_GITHUB=	yes
GH_ACCOUNT=	opscode
GH_PROJECT=	chef_wm
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	cf1cc5e

USE_GMAKE=	yes
ALL_TARGET=		compile
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

do-install:
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/priv
	${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/ebin/*.app  ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/*.erl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/include/*.hrl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/priv/*  ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/priv

.include <bsd.port.mk>
