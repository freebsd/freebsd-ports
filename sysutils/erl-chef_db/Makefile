# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	chef_db
PKGNAMEPREFIX=	erl-
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	GH

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	database application layer for the Chef server

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar \
	erl-chef_objects>=0:${PORTSDIR}/sysutils/erl-chef_objects \
	erl-couchbeam>=0:${PORTSDIR}/databases/erl-couchbeam \
	meck>=0:${PORTSDIR}/devel/meck \
	erl-sqerl>=0:${PORTSDIR}/databases/erl-sqerl \
	erl-stats_hero>=0:${PORTSDIR}/sysutils/erl-stats_hero \
	erl-ej>=0:${PORTSDIR}/devel/erl-ej \
	erl-depsolver>=0:${PORTSDIR}/devel/erl-depsolver \
	erl-envy>=0:${PORTSDIR}/devel/erl-envy

USE_GITHUB=	yes
GH_ACCOUNT=	opscode
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	ffd9c25

USE_GMAKE=	yes
ALL_TARGET=	compile
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

pre-build:
	${INSTALL} -d ${WRKSRC}/chef_db/include
	cp ${WRKSRC}/include/chef_db.hrl ${WRKSRC}/chef_db/include

do-install:
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/priv
	${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/ebin/*.app  ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/include/*.hrl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	# XXX src/chef_otto.hrl
	${INSTALL_DATA} ${WRKSRC}/src/*.hrl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/priv/*   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/priv
	${INSTALL_DATA} ${WRKSRC}/src/*.erl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
