# Created by: Lung-Pin Chang <changlp@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	dropbox-api-command
PORTVERSION=	1.13
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Dropbox API wrapper command

LICENSE=	MIT

BUILD_DEPENDS=	p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-Encode-Locale>=0:converters/p5-Encode-Locale \
		p5-JSON>=0:converters/p5-JSON \
		p5-WebService-Dropbox>=1.17:net/p5-WebService-Dropbox \
		p5-Path-Class>=0.26:devel/p5-Path-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	s-aska

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

# There is documentation contained in an otherwise empty library
# (App::dropboxapi). In post-patch copy it over to the main
# dropbox-api script so the perl build process makes a dropbox-api.1,
# and override do-install to only copy the useful parts, i.e., not the
# empty library.

PLIST_FILES=	bin/dropbox-api bin/upload-to-dropbox man/man1/dropbox-api.1.gz

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' ${WRKSRC}/upload-to-dropbox
	${TAIL} +3 ${WRKSRC}/lib/App/dropboxapi.pm >> ${WRKSRC}/dropbox-api

do-install:
	${INSTALL_MAN}    ${WRKSRC}/blib/man1/dropbox-api.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_SCRIPT} ${WRKSRC}/blib/script/dropbox-api ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/upload-to-dropbox       ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
