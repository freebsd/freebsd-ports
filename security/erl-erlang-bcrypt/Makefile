# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	erlang-bcrypt
PORTVERSION=	0.5.0.3
#PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	GH
PKGNAMEPREFIX=	erl-

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Wrapper around the OpenBSD's Blowfish hashing algorithm (opscode version)#'

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \

USE_GITHUB=	yes
GH_ACCOUNT=	opscode
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	466f0e3

ALL_TARGET=		compile
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

do-install:
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/priv
	${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/ebin/*.app  ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/*.erl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/priv/*      ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/priv

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
