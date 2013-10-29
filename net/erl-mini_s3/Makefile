# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	mini_s3
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	GH

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Robust Amazon S3 client for Erlang

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
	erl-ibrowse>=0:${PORTSDIR}/net/erl-ibrowse

USE_GITHUB=	yes
GH_ACCOUNT=	opscode
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	a9243b3

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
