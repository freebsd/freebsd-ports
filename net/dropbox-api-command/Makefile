# New ports collection makefile for:	dropbox-api-command
# Date created:		2011-07-14
# Whom:			Lung-Pin Chang <changlp@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dropbox-api-command
PORTVERSION=	20110512
CATEGORIES=	net
MASTER_SITES=	https://github.com/s-aska/${PORTNAME}/raw/${GITCOMMIT}/
DISTNAME=	dropbox-api
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Dropbox API wrapper command

RUN_DEPENDS=	p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Encode>=0:${PORTSDIR}/converters/p5-Encode \
		p5-Encode-Locale>=0:${PORTSDIR}/converters/p5-Encode-Locale \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Net-Dropbox-API>=0:${PORTSDIR}/net/p5-Net-Dropbox-API \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class

GITCOMMIT=	1cf7c825f2897db5d101e3cc53c9a5a4607235ee

USE_PERL5_RUN=	YES
NO_BUILD=	YES
FETCH_ARGS=	-pRr
PLIST_FILES=	bin/dropbox-api

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/dropbox-api ${PREFIX}/bin/dropbox-api

.include <bsd.port.mk>
