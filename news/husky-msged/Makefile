# New ports collection makefile for:    husky-msged
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	msged
PORTVERSION=	6.0.1
PORTREVISION=	2
CATEGORIES=	news mail
MASTER_SITES=	http://www.physcip.uni-stuttgart.de:8080/fidosoft.husky/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Msged/TE (full-featured FTN mail reader)

LIB_DEPENDS=	fidoconfig.0:${PORTSDIR}/news/husky-fidoconf

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ARGS=	MSGEDCFG="\\\"~/.msged\\\""

INFO=		msged

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
