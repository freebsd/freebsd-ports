# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	regripper
DISTVERSION=	2.5
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	rrv${DISTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Tool for registry analysis in forensics examinations

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	p5-Parse-Win32Registry>=0:${PORTSDIR}/devel/p5-Parse-Win32Registry

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_DOS2UNIX=	yes
NO_BUILD=	yes
USE_PERL5_RUN=	yes
PLIST_FILES=	bin/rip.pl

post-patch:
	${REINPLACE_CMD} -e 's|#! c:\\perl\\bin\\perl.exe|#!${PERL}| ; \
		s|plugindir = $$str|plugindir = "${DATADIR}"| ; \
		s|require "plugins\\\\|require "${DATADIR}plugins/|' ${WRKSRC}/rip.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rip.pl ${PREFIX}/bin

.include <bsd.port.mk>
