# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	chef_index
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	GH
PKGNAMEPREFIX=	erl-

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Search/indexing layer for chef

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar \
	erl-jiffy>=0:${PORTSDIR}/devel/erl-jiffy \
	erl-ibrowse>=0:${PORTSDIR}/net/erl-ibrowse \
	erl-ej>=0:${PORTSDIR}/devel/erl-ej \
	erl-gen_bunny-seth>=0:${PORTSDIR}/databases/erl-gen_bunny-seth \
	erl-envy>=0:${PORTSDIR}/devel/erl-envy \
	erl-amqp_client-seth>=0:${PORTSDIR}/databases/erl-amqp_client-seth

RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
	erl-jiffy>=0:${PORTSDIR}/devel/erl-jiffy \
	erl-ibrowse>=0:${PORTSDIR}/net/erl-ibrowse \
	erl-ej>=0:${PORTSDIR}/devel/erl-ej \
	erl-gen_bunny-seth>=0:${PORTSDIR}/databases/erl-gen_bunny-seth \
	erl-envy>=0:${PORTSDIR}/devel/erl-envy \
	erl-amqp_client-seth>=0:${PORTSDIR}/databases/erl-amqp_client-seth

USE_GITHUB=	yes
GH_ACCOUNT=	opscode
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	0f4ba30

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
	${INSTALL_DATA} ${WRKSRC}/priv/*   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/priv

.include <bsd.port.mk>
