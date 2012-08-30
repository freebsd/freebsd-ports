# New ports collection makefile for:	dropbox-api-command
# Date created:		2011-07-14
# Whom:			Lung-Pin Chang <changlp@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dropbox-api-command
PORTVERSION=	1.05
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Dropbox API wrapper command

RUN_DEPENDS=	p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Encode-Locale>=0:${PORTSDIR}/converters/p5-Encode-Locale \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-WebService-Dropbox>=1.09:${PORTSDIR}/net/p5-WebService-Dropbox \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class

USE_GITHUB=	yes
GH_ACCOUNT=	s-aska
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	cd3a707

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/dropbox-api bin/upload-to-dropbox

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' ${WRKSRC}/upload-to-dropbox

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dropbox-api ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/upload-to-dropbox ${PREFIX}/bin/

.include <bsd.port.mk>
