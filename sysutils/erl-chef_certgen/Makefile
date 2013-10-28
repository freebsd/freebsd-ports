# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	erl-chef_certgen
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	GH

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Erlang NIF that exposes some of the OpenSSL functionality

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar

USE_GITHUB=	yes
GH_ACCOUNT=	opscode
GH_PROJECT=	chef_certgen
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	d7c99d2

USE_GMAKE=	yes
ALL_TARGET=	compile
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

do-install:
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/priv
	${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/ebin/*.app  ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/include/*.hrl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/priv/*   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/priv
	${INSTALL_DATA} ${WRKSRC}/src/*.erl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src

.include <bsd.port.mk>
