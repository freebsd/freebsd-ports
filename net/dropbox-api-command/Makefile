# New ports collection makefile for:	dropbox-api-command
# Date created:		2011-07-14
# Whom:			Lung-Pin Chang <changlp@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dropbox-api-command
PORTVERSION=	1.00
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/s-aska/${PORTNAME}/raw/${PORTVERSION}/
DISTNAME=	dropbox-api
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Dropbox API wrapper command

RUN_DEPENDS=	p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Encode-Locale>=0:${PORTSDIR}/converters/p5-Encode-Locale \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-WebService-Dropbox>=0:${PORTSDIR}/net/p5-WebService-Dropbox \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class

FETCH_ARGS=	-pRr
NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/dropbox-api

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/dropbox-api ${PREFIX}/bin/dropbox-api

.include <bsd.port.mk>
