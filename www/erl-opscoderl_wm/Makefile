# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	opscoderl_wm
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	GH
PKGNAMEPREFIX=	erl-

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Opscode helpers for Webmachine

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar \
	webmachine>=0:${PORTSDIR}/www/webmachine
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
	webmachine>=0:${PORTSDIR}/www/webmachine

USE_GITHUB=	yes
GH_ACCOUNT=	opscode
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	bbfa553

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
